#include "MedicalResponders.h"


void MedicalResponders::attendIncident() {
    std::string String = "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    String += "+ Stage:                                                            Incident Response  +\n";
    String += "+ Patient_Condition:                                          Conscious, minor injury  +\n";
    String += "+ Treatment_Given:                                          Wound cleaned, bandaged  +\n";
    String += "+ Vitals_Checked:                                                     Stable, normal  +\n";
    String += "+ Transport_Required:                                                            No  +\n";
    String += "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    std::cout << String << std::endl;
}

void MedicalResponders::leaveScene() {
    std::string String = "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    String += "+ Stage:                                                                 Scene Exit  +\n";
    String += "+ Patient_Status:                                                Stable, self-caring  +\n";
    String += "+ Report_Filed:                                                                Yes  +\n";
    String += "+ Follow_Up_Required:                                        Recommended GP visit  +\n";
    String += "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    std::cout << String << std::endl;
}