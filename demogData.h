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

    double getBAup() { return 100.0f*(double)(popBachelors)/getPop();; }
    double getHSup() { return 100.0f*(double)(popHighSchool)/getPop();; }
    double getPopOver65() { return 100.0f*(double)(popOver65)/getPop(); }
    double getPopUnder18() { return 100.0f*(double)(popUnder18)/getPop(); }
    double getPopUnder5() { return 100.0f*(double)(popUnder5)/getPop(); }
    double getPov() { return 100.0f*(double)(belowPovertyLevel)/getPop(); }
  
    int getPopOver65Count() { return popOver65; }
    int getPopUnder18Count() { return popUnder18; }
    int getPopUnder5Count() { return popUnder5; }
    int getBAupCount() { return popBachelors; }
    int getHSupCount() { return popHighSchool; }
    int getPovCount()  { return belowPovertyLevel; }

    raceDemogData& getRacialData() { return racialData; }

    friend std::ostream& operator<<(std::ostream &out, demogData &DD);

protected:
    int popOver65;
    int popUnder18;
    int popUnder5;
    int popBachelors;
    int popHighSchool;
    int belowPovertyLevel;
    raceDemogData racialData;

};
#endif
