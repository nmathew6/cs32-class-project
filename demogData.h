#ifndef DEMOG_H
#define DEMOG_H

#include <string>
#include<iostream>
#include <cmath>
#include "raceDemogData.h"
#include "regionData.h"

using namespace std;

/*
  class to represent county demographic data
  from CORGIS
*/
class demogData : public regionData  {
  public:    
    demogData() : regionData(" ", " ", 0), popOver65(0), popUnder18(0), popUnder5(0), popBachelors(0), popHighSchool(0), belowPovertyLevel(0), racialData() {}
    demogData(string inN) : regionData(inN), popOver65(0), popUnder18(0), popUnder5(0), popBachelors(0), popHighSchool(0), belowPovertyLevel(0), racialData() {}
    demogData(string inN, string inS, double in65, double in18, double in5, double BAup, double HSup, double poverty, double totPop14, raceDemogData race) :
      regionData(inN, inS, totPop14), popOver65(in65), popUnder18(in18), popUnder5(in5), popBachelors(BAup), popHighSchool(HSup), belowPovertyLevel(poverty), racialData(race) {}

    double getBAup() { return popBachelors; }
    double getHSup() { return popHighSchool; }
    double getPopOver65() { return popOver65; }
    double getPopUnder18() { return popUnder18; }
    double getPopUnder5() { return popUnder5; }
    double getPov() { return belowPovertyLevel; }
  
    double getPopOver65Count() { return ((popOver65 * static_cast<double>(population)/100)); }
    double getPopUnder18Count() { return ((popUnder18 * static_cast<double>(population)/100)); }
    double getPopUnder5Count() { return ((popUnder5 * static_cast<double>(population)/100)); }
    double getBAupCount() { return ((popBachelors * static_cast<double>(population)/100)); }
    double getHSupCount() { return ((popHighSchool * static_cast<double>(population)/100)); }
    double getPovCount()  { return ((belowPovertyLevel * static_cast<double>(population)/100));  }

    raceDemogData& getRacialData() { return racialData; }

    friend std::ostream& operator<<(std::ostream &out, demogData &DD);

protected:
    double popOver65;
    double popUnder18;
    double popUnder5;
    double popBachelors;
    double popHighSchool;
    double belowPovertyLevel;
    raceDemogData racialData;

};
#endif
