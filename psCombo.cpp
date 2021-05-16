#include <iomanip>
#include "psCombo.h"



/* print state data - as aggregate of all incidents in this state 
std::ostream& operator<<(std::ostream &out, psCombo& PD) {
    out << "**Police shooting incidents:State Info: " << PD.getRegionName();
    out << "\nNumber of incidents: " << PD.getNumberOfCases();
    out << std::setprecision(2) << std::fixed;
    out << "\nIncidents with age \n(over 65): " << PD.getCasesOver65();
    out << "\n(19 to 64): " << PD.getNumberOfCases()-PD.getCasesUnder18()-PD.getCasesOver65();
    out << "\n(under 18): " << PD.getCasesUnder18();
    out << "\nIncidents involving fleeing: " << PD.getFleeingCount();
    out << "\nIncidents involving mental illness: " << PD.getNumMentalI();
    out << "\nMale incidents: " <<  PD.getnumMales() << " female incidents: " << PD.getnumFemales();
    out << "\nRacial demographics of state incidents: " << PD.getRacialData();
    return out;
}
*/

std::ostream& operator<<(std::ostream &out, psCombo& PD)
{
    //out << "key: " << PD.getRaceKey() << endl;
    out << "State Info: " << PD.printStatesWithSize();
    out << "\nNumber of incidents: " << PD.getNumberOfCases();
    out << fixed << showpoint << setprecision(2);
    out << "\nIncidents with age \n(over 65): " << PD.getCasesOver65() << " %: " << 100.0 * PD.getCasesOver65()/PD.getNumberOfCases();
    out << "\n(19 to 64): " << PD.getNumberOfCases()-PD.getCasesUnder18()-PD.getCasesOver65() << " %: " << 100.0 * (PD.getNumberOfCases()-PD.getCasesUnder18()-PD.getCasesOver65())/PD.getNumberOfCases();
    out << "\n(under 18): " << PD.getCasesUnder18() << " %: " << 100.0 * PD.getCasesUnder18()/PD.getNumberOfCases();
    out << "\nIncidents involving fleeing: " << PD.getFleeingCount() << " %: " << 100.0 * PD.getFleeingCount()/PD.getNumberOfCases();
    out << "\nIncidents involving mental illness: " << PD.getNumMentalI() << " %: " << 100.0 * PD.getNumMentalI()/PD.getNumberOfCases();
    out << "\nMale incidents: " <<  PD.getnumMales() << " female incidents: " << PD.getnumFemales();
    //out << "\nRacial demographics of state incidents: " << PD.getRacialData();
    return out;
}
