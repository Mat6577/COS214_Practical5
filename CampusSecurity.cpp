#include "CampusSecurity.h"

void CampusSecurity::attendIncident() {
    std::string String = "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    String += "+ Stage:                                                            Incident Response  +\n";
    String += "+ Report_Received:                                   Suspicious activity, Lot C   +\n";
    String += "+ Officer_Dispatched:                                          Officer M. Dlamini  +\n";
    String += "+ Action_Taken:                                    Approached, questioned subject  +\n";
    String += "+ Outcome:                                       Verified student ID, no incident  +\n";
    String += "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    std::cout << String << std::endl;
}

void CampusSecurity::leaveScene() {
    std::string String = "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    String += "+ Stage:                                                                 Scene Exit  +\n";
    String += "+ Area_Status:                                                      Cleared/Secured  +\n";
    String += "+ Report_Filed:                                                                Yes  +\n";
    String += "+ Follow_Up_Required:                                                           No  +\n";
    String += "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    std::cout << String << std::endl;
}