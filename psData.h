#ifndef POLICE_H
#define POLICE_H

#include <string>
#include <iostream>
#include <utility>
#include "regionData.h"

using namespace std;

/*
  class to represent police shooting data
  from CORGIS
*/
class psData : public regionData  {
  public:
    //add appropriate function paramaters to constructor once you add data
    psData() : regionData() {}
    psData(string inS, string inN, int inA, string inG, string inR, 
        string inC, bool inM, string inF) : regionData(inC, inS), name(inN), age(inA), gender(inG), race(inR), signs_of_mental_illness(inM), flee(inF) {}

    string getName() { return name; }
    int getAge() { return age; }
    string getGender() { return gender; }
    bool getMentalI() { return signs_of_mental_illness; }
    string getFlee() { return flee; }
    string getRace() { return race; }

   friend std::ostream& operator<<(std::ostream &out, psData &PD);
   //void toString(ostream& os) const 

protected:
    string name;
    int age;
    string gender; 
    string race;
    bool signs_of_mental_illness;
    string flee;
};

#endif
