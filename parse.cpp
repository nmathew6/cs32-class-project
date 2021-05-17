/* helper routines to read out csv data */
#include "parse.h"
#include <algorithm>
#include <cmath>

/* helper to strip out quotes from a string */
string stripQuotes(std::string temp) {
    temp.erase(
        remove(temp.begin(), temp.end(), '\"' ),
        temp.end());
    return temp;
}

/* helper: get field from string stream */
/* assume field has quotes for CORGIS */
string getField(std::stringstream &ss) {
    string data, junk;
    //ignore the first quotes
    std::getline(ss, junk, '\"');
    //read the data (not to comma as some data includes comma (Hospital names))
    std::getline(ss, data, '\"');
    //read to comma final comma (to consume and prep for next)
    std::getline(ss, junk, ',');
    //data includes final quote (see note line 18)
    return stripQuotes(data);
}

string getFieldNQ(std::stringstream &ss)
{
    string temp;
    std::getline(ss, temp, ',');
    //std::cout << temp << std:: endl;
    return temp;
}

/* helper: read out column names for CSV file */
void consumeColumnNames(std::ifstream &myFile) {
    std::string line;
    std::string colname;

    // Extract the first line in the file
    std::getline(myFile, line);

    // Create a stringstream from line
    std::stringstream ss(line);

    // Read the column names (for debugging)
    // Extract each column name for debugging
    while(std::getline(ss, colname, ',')) {
    //    std::cout << colname << std::endl;
    }
}

//read from a CSV file (for a given data type) return a vector of the data
// DO NOT modify 
std::vector<shared_ptr<regionData>> read_csv(std::string filename, typeFlag fileType) {
    //the actual data
    std::vector<shared_ptr<regionData>> dem;
    std::vector<shared_ptr<regionData>> ps;
    bool check = false;

    // Create an input filestream
    std::ifstream myFile(filename);

    // Make sure the file is open
    if(!myFile.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    if(myFile.good()) {
        consumeColumnNames(myFile);

        // Helper vars
        std::string line;
        

        // Now read data, line by line and create demographic dataobject
        while(std::getline(myFile, line)) {
            if (fileType == DEMOG) {
                check = true;
                dem.push_back(readCSVLineDemog(line));
            } 
            else if(fileType == POLICE){
                ps.push_back((readCSVLinePolice(line)));
            }
        }

        // Close file
        myFile.close();
    }
    if(check){
        return dem;
    }
    else{
        return ps;
    }

}

/* Read one line from a CSV file for county demographic data specifically */
shared_ptr<demogData> readCSVLineDemog(std::string theLine) {
    std::stringstream ss(theLine);
    
    string name = getField(ss);
    string state = getField(ss);
    //turn into mathematical percent
    double popOver65 = stod(getField(ss))/100.0;
    double popUnder18 = stod(getField(ss))/100.0;
    double popUnder5 = stod(getField(ss))/100.0;
    double bachelorDegreeUp = stod(getField(ss))/100.0;
    double highSchoolUp = stod(getField(ss))/100.0;

    //now skip over some data
    for (int i=0; i < 4; i++)
        getField(ss);

    //store initial data as percent (then convert to count)
    double FirstNation= stod(getField(ss))/100.0;
    double Asian= stod(getField(ss))/100.0;
    double Black= stod(getField(ss))/100.0;
    double Latinx= stod(getField(ss))/100.0;
    double HIPacificIsle= stod(getField(ss))/100.0;
    double MultiRace= stod(getField(ss))/100.0;
    double White= stod(getField(ss))/100.0;
    double WhiteNH = stod(getField(ss))/100.0;

    //now skip over some data 
    for (int i=0; i < 6; i++)
        getField(ss);

    int medHouseIncome = stoi(getField(ss)); //dont use
    //skip per capita
    getField(ss);
    double belowPoverty = stod(getField(ss))/100.0;

    //now skip over some data 
    for (int i=0; i < 10; i++)
        getField(ss);

    int totalPop2014 = stoi(getField(ss));

    popOver65 = round(popOver65*totalPop2014);
    popUnder18 = round(popUnder18*totalPop2014);
    popUnder5 = round(popUnder5*totalPop2014);
    bachelorDegreeUp = round(bachelorDegreeUp*totalPop2014);
    highSchoolUp = round(highSchoolUp*totalPop2014);
    belowPoverty = round(belowPoverty*totalPop2014);
    
    double FirstNationCount = round(FirstNation * totalPop2014);
    double AsianCount = round(Asian * totalPop2014);
    double BlackCount = round(Black * totalPop2014);
    double LatinxCount = round(Latinx * totalPop2014);
    double HIPacificIsleCount = round(HIPacificIsle * totalPop2014);
    double MultiRaceCount = round(MultiRace * totalPop2014);
    double WhiteCount = round(White * totalPop2014);
    double WhiteNHCount = round(WhiteNH * totalPop2014);

    raceDemogData racialData(FirstNationCount, AsianCount, BlackCount, LatinxCount, HIPacificIsleCount, 
            MultiRaceCount, WhiteCount, WhiteNHCount, totalPop2014);
 
    //update as needed this is lab3 version
    return make_shared<demogData>(name, state, popOver65, popUnder18,
            popUnder5, bachelorDegreeUp, highSchoolUp, belowPoverty, 
            totalPop2014, racialData);
}

//read one line of police data
shared_ptr<psData> readCSVLinePolice(std::string theLine) {
    std::stringstream ss(theLine);
    
    getFieldNQ(ss); //ignore id
    string name = getFieldNQ(ss);
    for(int i = 0; i < 3; i++){
        getFieldNQ(ss);
    }
    int age = 0;
    string tmp = getFieldNQ(ss);
    if(tmp != ""){
        age = stoi(tmp);
    }
    else{
        age = -1;
    }
    string gender = getFieldNQ(ss);
    string race = getFieldNQ(ss);
    string city = getFieldNQ(ss);
    string state = getFieldNQ(ss);
    //finish reading other data fields and initialize police data
    
    //DEBUG STUFF 
    string temp = getFieldNQ(ss);
    bool mentalIllness = (temp == "True");
    getFieldNQ(ss);

    string flee = getFieldNQ(ss);

    return make_shared<psData>(state, name, age, gender, race, city, mentalIllness, flee);
}



