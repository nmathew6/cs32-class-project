#include <iomanip>
#include "psCombo.h"



/* print state data - as aggregate of all incidents in this state */
std::ostream& operator<<(std::ostream &out, psCombo& PD) {
    out << "**Police shooting incidents:State Info: " << PD.getState();
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
