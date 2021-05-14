#include "demogCombo.h"
#include "demogData.h"
#include <sstream>
#include <string>
#include <assert.h>
#include <iomanip>


//add member functions here

/* print state data - as aggregate of all the county data */
std::ostream& operator<<(std::ostream &out, demogCombo &SD) {
    out << "State Demographic Info: State Info: " << SD.getState() << endl;
    out << "Number of Counties: " << SD.getNumCounties() << endl;
    out << fixed << showpoint << setprecision(2);
    out << "Population info:" << endl;
    out << "(over 65): " << SD.getPopOver65() << "% and total: " << static_cast<int>(SD.getPopOver65Count()+.5) << endl;
    out << "(under 18): " << SD.getPopUnder18() << "% and total: " << static_cast<int>(SD.getPopUnder18Count()+.5) << endl;
    out << "(under 5): " << SD.getPopUnder5() << "% and total: " << static_cast<int>(SD.getPopUnder5Count()+.5) << endl;
    out << "Education info:" << endl;
    out << "(Bachelor or more): " << SD.getBAup() << "% and total: " << static_cast<int>(SD.getBAupCount()+.5) << endl;
    out << "(high school or more): " << SD.getHSup() << "% and total: " << static_cast<int>(SD.getHSupCount()+.5) << endl;
    out << "persons below poverty: " << SD.getPov()*100 << "% and total: " << static_cast<int>(SD.getPovCount()+.5) << endl;
    out << "community racial demographics: " << SD.getRacialData();
    out << " Total population: " << static_cast<int>(SD.getPop()) << endl;
    return out;
}
