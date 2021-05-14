#include <sstream>
#include "psData.h"

/* print police data - fill in*/
std::ostream& operator<<(std::ostream &out, psData &PD) {
    out << "Police Shooting Info: " << PD.getState();
    out << "\nPerson name: " << PD.getName();
    out << "\nAge: " << PD.getAge();
    out << "\nGender: " << PD.getGender();
    out << "\nRace:"  << PD.getRace();
    out << "\nMental Illness:" << PD.getMentalI();
    out << "\nFleeing:" << PD.getFlee();
    return out;
}

