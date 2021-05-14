#include "demogData.h"
#include <sstream>
#include <iomanip>

/* print county demographic data */
std::ostream& operator<<(std::ostream &out, demogData &DD) {
    out << "County Demographics Info: " << DD.getRegionName() << ", " << DD.getState();
    out << " total population: " << DD.getPop();
    //consider re-writing with getters....
    out << "\nPopulation info: \n(\% over 65): " << std::setprecision(2) << DD.getPopOver65();
    out <<  " Count: " << DD.getPopOver65Count();
    out << "\n(\% under 18): " << std::setprecision(2) << DD.getPopUnder18();
    out <<  " Count: " << DD.getPopUnder18Count();
    out << "\n(\% under 5): " << std::setprecision(2) << DD.getPopUnder5();
    out <<  " Count: " << DD.getPopUnder5Count();
    out << "\nEducation info: ";
    out << "\n(% Bachelor degree or more): " << std::setprecision(2) << DD.getBAup();
    out << " Count: " << DD.getBAupCount();
    out << "\n(% high school or more): " << std::setprecision(2) << DD.getHSup();
    out << " Count: " << DD.getHSupCount();
    out << "\n(% Percentage population below poverty line): " << std::setprecision(2) << DD.getPov();
    return out;
}
