#ifndef REGION_H
#define REGION_H

#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace std;


/* very general data type for any kind of regional data*/
class regionData {
  public:
    regionData() {}
    regionData(const string inN, const string inS, const double pop) : regionName(inN), population(pop) {
      stateS.insert(inS);
    }
    regionData(const string inN, const string inS) : regionName(inN), population(0) {
      stateS.insert(inS);
    }
    regionData(const string inS) : regionName(""), population(0) {
      stateS.insert(inS);
    }

    string getRegionName() const {return regionName;}
    string getState() const {if (stateS.size() == 1) return *(stateS.begin()); else return "many";}
    void addState(string inS) {stateS.insert(inS);}
    string printState() const {
      string s;
      for (std::set<string>::iterator it=stateS.begin(); it != stateS.end(); it++)
        s += "total states: " + std::to_string(stateS.size());
        return s;
    }
    string printStatesWithSize() const{
      string s;
      for (std::set<string>::iterator it=stateS.begin(); it != stateS.end(); it++)
        s += *it + ", ";
      s+= "total states: " + std::to_string(stateS.size());
      return s;
    }
    void setName(string inN) {regionName = inN;}
    int getPop() const {return population;}
    void setPop(int inPop) {population = inPop;}

    //virtual void toString(ostream& os) const = 0;

  protected:
    string regionName; // city or county or place name
    // region data could be more than one state
    std:: set<string> stateS; // all reagions should have identifying state in US
    int population; // region population
};
#endif
