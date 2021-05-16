#ifndef POLICECOMBODATA_H
#define POLICECOMBODATA_H

#include "raceDemogData.h"
#include "regionData.h"
#include "psData.h"
#include <memory>
#include <cassert>

using namespace std;

class psCombo : public regionData  {
public:
    psCombo() : regionData() {}
    psCombo(string inS) : regionData(inS), numMentalI(0), fleeingCount(0),
        casesOver65(0), casesUnder18(0), racialData(), numMales(0),
        numFemales(0), numCases(0), raceKey("") {} //add
  
    //complete these
    int getNumMentalI() const{ return numMentalI; }
    int getFleeingCount() const{ return fleeingCount; }
    int getCasesOver65() const { return casesOver65; }
    int getCasesUnder18() const { return casesUnder18; }
    raceDemogData& getRacialData() {return racialData;}
    int getnumMales() const{ return numMales; }
    int getnumFemales() const{ return numFemales; }
    int getNumberOfCases() const{ return numCases; }

    string getRaceKey() const { return raceKey; }
    void setRaceKey(string theKey) { raceKey = theKey; }

    //add any others needed
    friend std::ostream& operator<<(std::ostream &out, psCombo& PD);

    void addData(shared_ptr<psData> a) { 
        if (a->getMentalI()) {
            numMentalI++;
        }
        if ((a->getFlee() == "Car") || (a->getFlee() == "Foot") || (a->getFlee() == "Other")) {
            fleeingCount++;
        }
        if (a->getRace() == "A") {
            racialData.addAsianCount(1);
            // racialData.addCommunityCount(1);
        }
        if (a->getRace() == "B") {
            racialData.addBlackCount(1);
            // racialData.addCommunityCount(1);
        }
        if (a->getRace() == "H") {
            racialData.addLatinxCount(1);
        if (a->getRace() == "N")
            racialData.addFirstNationCount(1);
            // racialData.addCommunityCount(1);
        }
        if (a->getRace() == "O" || a->getRace() == "") {
            racialData.addOtherCount(1);
            // racialData.addCommunityCount(1);
        }
        if (a->getRace() == "W") {
            racialData.addWhiteCount(1);
            racialData.addWhiteNHCount(1);
            // racialData.addCommunityCount(1);
        }
        if (a->getAge() > 65)
            casesOver65++;
        else if (a->getAge() < 18)
            casesUnder18++;
            
        if (a->getGender() == "M")
            numMales++;
        else if (a->getGender() == "F")
            numFemales++;
        numCases++;
    }


protected:
    double numMentalI;                                                                                                                                                                 
    double fleeingCount;
    double casesOver65; 
    double casesUnder18;
    double numCases;
    double numMales;
    double numFemales;
    raceDemogData racialData;

    string raceKey;    
};

#endif
