#ifndef COMBODEMOG_H
#define COMBODEMOG_H

#include <memory>
#include <string>
#include <iostream>
#include "demogData.h"
#include "raceDemogData.h"

/*
  class to represent combined demographic data 
*/
class demogCombo : public demogData {
  public:
        //write demogCombo constructor
  demogCombo() : demogData(), numCounties(0) {} 
  demogCombo(string inN, string inS, double in65, double in18, double in5, double BAup, double HSup, double pov, double totPop14, raceDemogData race, int numC) : 
    demogData(inN, inS, in65, in18, in5, BAup, HSup, pov, totPop14, race), numCounties(numC) {}
  demogCombo(demogData DD) : 
        demogData(DD.getRegionName(), DD.getState(), DD.getPopOver65(), DD.getPopUnder18(), DD.getPopUnder5(), 
        DD.getBAup(), DD.getHSup(), DD.getPov(), DD.getPop(), DD.getRacialData()), numCounties(0) {}
      
//fill in
  int getNumCounties() { return numCounties; }
  void setNumCounties() {numCounties++; }

  void addData(shared_ptr<demogData> a) { 
    popOver65 = (a->getPopOver65Count()+getPopOver65Count())/(a->getPop()+getPop())*100.0;
    popUnder18 = (a->getPopUnder18Count()+getPopUnder18Count())/(a->getPop()+getPop())*100.0;  
    popUnder5 = (a->getPopUnder5Count()+getPopUnder5Count())/(a->getPop()+getPop())*100.0;
    popBachelors = (a->getBAupCount()+getBAupCount())/(a->getPop()+getPop())*100.0; 
    popHighSchool = (a->getHSupCount()+getHSupCount())/(a->getPop()+getPop())*100.0; 
    belowPovertyLevel = (a->getPovCount()+getPovCount())/(a->getPop()+getPop())*100.0;
    population += a->getPop(); 
    racialData += a->getRacialData();
    numCounties++;
  }

  // void addOver65(demogData a) { 
  //   popOver65 = (a.getPopOver65Count()+getPopOver65Count())/(a.getPop()+getPop())*100.0;
  //   }
  // void addUnder18(demogData a) { 
  //   popUnder18 = (a.getPopUnder18Count()+getPopUnder18Count())/(a.getPop()+getPop())*100.0;  
  //   }
  // void addUnder5(demogData a) { 
  //   popUnder5 = (a.getPopUnder5Count()+getPopUnder5Count())/(a.getPop()+getPop())*100.0;
  //   }
  // void addBAup(demogData a) { 
  //   popBachelors = (a.getBAupCount()+getBAupCount())/(a.getPop()+getPop())*100.0; 
  //   }
  // void addHSup(demogData a) { 
  //   popHighSchool = (a.getHSupCount()+getHSupCount())/(a.getPop()+getPop())*100.0; 
  //   }
  // void addPOV(demogData a) { 
  //   belowPovertyLevel = (a.getPovCount()+getPovCount())/(a.getPop()+getPop())*100.0;
  //   }
  // void addTotalPop(demogData a) { 
  //   population += a.getPop(); 
  //   }

  // void addNumCounties(demogData a) {
  //   numCounties++;
  //   }

  // demogCombo& operator+=(demogData dd) {
  //   this->addOver65(dd);
  //   this->addUnder18(dd);
  //   this->addUnder5(dd);
  //   this->addBAup(dd);
  //   this->addHSup(dd);
  //   this->addPOV(dd);
  //   this->addTotalPop(dd);
  //   this->addNumCounties(dd);
  //   this->getRacialData() += dd.getRacialData();
  //   return *this;
  //   }

  friend std::ostream& operator<<(std::ostream &out, demogCombo &SD);

private:
    int numCounties;
};
#endif
