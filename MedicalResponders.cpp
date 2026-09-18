#include "MedicalResponders.h"

void MedicalResponders::assessScene() {
    std::string String = "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    String += "+ Stage:                                                          Scene Assessment  +\n";
    String += "+ Hazards_Checked:                                     Traffic, fire, crowd control  +\n";
    String += "+ Patients_Identified:                                                            1  +\n";
    String += "+ Scene_Safety:                                                       Confirmed Safe  +\n";
    String += "+ Decision:                                                 Proceed with treatment  +\n";
    String += "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    std::cout << String << std::endl;
}

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