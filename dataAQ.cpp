/* aggregate data */
#include "dataAQ.h"
#include "demogData.h"
#include "psData.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

dataAQ::dataAQ() {}

string makeKeyExample(shared_ptr<demogData> theData) {


  string theKey = "Key";

/*
  if (theData->getBelowPoverty() < 10) {
    theKey += "BelowPovLessTenPer";
  } else if (theData->getBelowPoverty() < 20) {
    theKey += "BelowPovLessTwentyPer";
  } else if (theData->getBelowPoverty() < 30) {
    theKey += "BelowPovLessThirtyPer";
  } else {
    theKey += "BelowPovAboveThirtyPer";
  }
*/
  return theKey;
}


string makeKeyExample(shared_ptr<psData> theData) {

  string theKey = "Key";
  /*
  if (theData->getFleeing() == "Foot") {
    theKey += "FleeingOnFoot";
  } else if (theData->getFleeing() == "Car") {
    theKey += "FleeingByCar";

  } else if (theData->getFleeing() == "Other") {
    theKey += "FleeingOtherMeans";
  } else {
    theKey += "NotFleeing";
  }
  */
  return theKey;
}


//swtich to a function parameter
void dataAQ::createComboDemogDataKey(std::vector<shared_ptr<demogData> >& theData) {

//fill in

}

void dataAQ::createComboPoliceDataKey(std::vector<shared_ptr<psData> >& theData) {
//fill in

}

bool compareState(shared_ptr<psData> ps1, shared_ptr<psData> ps2) 
{ 
  return ps1->getState() < ps2->getState(); 
}

/******************************************/
/* state examples */
void dataAQ::createComboDemogData(std::vector<shared_ptr<demogData>> theData) {
  auto current = make_shared <demogCombo>();
  current->setName(theData[0]->getState());
  for (int i = 0 ; i  < theData.size(); i++) {
    demogData current_data = *theData[i];
    if (current_data.getState() != current->getRegionName()) {
      allComboDemogData.insert(std::pair<string, shared_ptr<demogCombo>>(current->getRegionName(), current));  
      current = make_shared <demogCombo>();
      current->setName(current_data.getState());
    }
    current->addXtoAggregate(theData[i]);
  }
}

void dataAQ::createComboPoliceData(std::vector<shared_ptr<psData>> theData) {
  auto current = make_shared<psCombo>();
  sort(theData.begin(), theData.end(), compareState);
  current->setName(theData[0]->getState());
  for (int i = 0; i < theData.size(); i++)
  {
    psData current_data = *theData[i];
    if (current_data.getState() != current->getRegionName())
    {
      allComboPoliceData.insert(std::pair<string, shared_ptr<psCombo>>(current->getRegionName(), current));
      current = make_shared<psCombo>();
      current->setName(current_data.getState());
    }
    current->addData(theData[i]);
  }
}

bool comparePS(psCombo& a, psCombo& b) {
    return a.getNumberOfCases() > b.getNumberOfCases();
}

bool compareBP(demogCombo& a, demogCombo& b) {
    return a.getPov() > b.getPov();
}

void dataAQ::reportTopTenStatesPS() {
    vector<psCombo> states;
    for (auto &obj : this->allComboPoliceData) {
        states.push_back(*(obj.second));
    }
    sort(states.begin(),states.end(),comparePS);
    cout << "Top ten states sorted in terms of number of police shootings:" << endl;
    for (int i=0; i<10; i++) {
        cout << setprecision(0) << fixed;
        cout << states[i].getRegionName() << endl;
        cout << "Total population: " << getComboDemogData(states[i].getRegionName())->getPop() << endl;
        cout << "Police shooting incidents: " <<  getComboPoliceData(states[i].getRegionName())->getNumberOfCases() << endl;
        cout << setprecision(2) << fixed;
        cout << "Percent below poverty: " << getComboDemogData(states[i].getRegionName())->getPov()*100 << endl;
    }
    cout << "\n**Full listings for top 3 police shooting data and associated data: " << endl;
    for (int j=0; j<3; j++) {
        cout << *(getComboDemogData(states[j].getRegionName()));
        cout << *(getComboPoliceData(states[j].getRegionName())) << endl;
    }
}

void dataAQ::reportTopTenStatesBP() {
    vector<demogCombo> states;
    for (auto &obj : this->allComboDemogData) {
        states.push_back(*(obj.second));
    }
    sort(states.begin(),states.end(),compareBP);
    cout << "Top ten states sorted on Below Poverty data & the associated police shooting data:\n";
    for (int i=0; i<10; i++) {
        cout << setprecision(0) << fixed;
        cout << states[i].getRegionName() << endl;
        cout << "Total population: " << getComboDemogData(states[i].getRegionName())->getPop() << endl;
        cout << setprecision(2) << fixed;
        cout << "Percent below poverty: " << getComboDemogData(states[i].getRegionName())->getPov()*100.0 << endl;
        cout << setprecision(0) << fixed;
        cout << "Police shooting incidents: " << getComboPoliceData(states[i].getRegionName())->getNumberOfCases() << endl;
    }
    cout << "**Full listings for top 3 Below Poverty data & the associated police shooting data for top 3:\n";
    for (int j=0; j<3; j++) {
        cout << *(getComboDemogData(states[j].getRegionName())) << endl;
        cout << *(getComboPoliceData(states[j].getRegionName())) << endl;
    }
}
/* print all combo data */
std::ostream& operator<<(std::ostream &out, const dataAQ &theAnswers) {
  out << "Combo Demographic Info: ";
  for (auto const& entry : theAnswers.allComboDemogData) {
      out << "key: " << entry.first << endl;
      out << *(entry.second) << "\n";

  }

  for (auto const& entry : theAnswers.allComboPoliceData) {
      out << "key: " << entry.first << endl;
      out << *(entry.second) << "\n";

  }

  return out;
}
