    // Standard libraries
#include <iostream>
#include <memory>

    // Self defined libraries
#include "AccessControl.h"
#include "AccessControlSystem.h"
#include "CampusComponent.h"
#include "CampusSecurity.h"
#include "Command.h"
#include "CommunicationService.h"
#include "ConcreteEmergencyCoordinator.h"
#include "DispatchUnitCommand.h"
#include "EmergencyCoordinator.h"
#include "IssueAlertCommand.h"
#include "LegacyAccessControlSystem.h"
#include "MedicalResponders.h"
#include "OperatorConsole.h"
#include "SecureAreaCommand.h"
#include "Stages.h"
#include "Detection.h"
#include "Response.h"
#include "Recovery.h"
#include "ResponseComponent.h"


// A minimal dummy receiver just to test your State pattern output
// class DummyReceiver : public ResponseComponent {
// public:
//     // Added 'const' to match the base class perfectly
//     void triggerEvent(const std::string& event) override {
//         std::cout << "  -> Receiver caught event: " << event << "\n";
//     }

//     void receiveNotification(const std::string& event) override {
//         std::cout << "  -> Receiver notified: " << event << "\n";
//     }
// };

// void NavelasTest() {
//     // 1. Instantiate the receiver (Context)
//     DummyReceiver testReceiver;

//     // 2. Initialize with Detection State
//     std::cout << "=== INITIALIZING DETECTION STATE ===\n";
//     testReceiver.changeStage(std::unique_ptr<Stages>(new Detection()));
    
//     // Test routing (Alert should work, Dispatch should fail)
//     testReceiver.requestAlert();    
//     testReceiver.requestDispatch(); 


//     // 3. Transition to Response State
//     std::cout << "\n=== TRANSITIONING TO RESPONSE STATE ===\n";
//     testReceiver.changeStage(std::unique_ptr<Stages>(new Response()));
    
//     // Test routing (Dispatch should work, Secure should fail)
//     testReceiver.requestDispatch(); 
//     testReceiver.requestSecure();   


//     // 4. Transition to Recovery State
//     std::cout << "\n=== TRANSITIONING TO RECOVERY STATE ===\n";
//     testReceiver.changeStage(std::unique_ptr<Stages>(new Recovery()));
    
//     // Test routing (Secure should work, Alert should fail)
//     testReceiver.requestSecure();   
//     testReceiver.requestAlert();    

// }

int main() {
    // NavelasTest();

    std::string issue1 = "Student strike outside the school";
    std::string issue2 = "Student strike outside the school";

        // CommunicationService
    CommunicationService* campusSecurity = new CampusSecurity();
    Command* issueAlertSecurity = new IssueAlertCommand(campusSecurity, issue1);

    CommunicationService* medicalResponders = new MedicalResponders();
    Command* issueAlertMedical = new IssueAlertCommand(medicalResponders, issue2);


        // OperatorConsole
        
    OperatorConsole* operatorConsole = new OperatorConsole();

        // AccessControlSystem
    AccessControlSystem* accessControlSystem = new AccessControlSystem();

        // CampusSomponent
    CampusComponent* studentHall = new CampusComponent();

        // SecureAreaCommand
    Command* secureArea = new SecureAreaCommand(accessControlSystem, studentHall);


        // Stages
    accessControlSystem->changeState();



        // OperatorConsole
    operatorConsole->executeCommand(issueAlertMedical);
    operatorConsole->executeCommand(issueAlertSecurity);
    operatorConsole->executeCommand(secureArea);

        // State Changing
    medicalResponders->changeState();
    campusSecurity->changeState();

    Command* comm = operatorConsole->getCommand(2);
    if (comm) {
        comm->execute();
    }

    ConcreteEmergencyCoordinator* emergencyCoordinator = new ConcreteEmergencyCoordinator();


    emergencyCoordinator->addComponent(campusSecurity);
    emergencyCoordinator->addComponent(medicalResponders);
    emergencyCoordinator->addComponent(accessControlSystem);

    campusSecurity->setMediator(emergencyCoordinator);
    medicalResponders->setMediator(emergencyCoordinator);

    emergencyCoordinator->notify(accessControlSystem);
    
    operatorConsole->undoLast();
    operatorConsole->undoLast();

    operatorConsole->removeCommand(secureArea);


    CampusSecurity* campus2Security = new CampusSecurity();
    DispatchUnitCommand* dispatch = new DispatchUnitCommand(campus2Security, "Hall1");

    campus2Security->requestAlert();
    campus2Security->requestDispatch();
    campus2Security->requestSecure();

    std::unique_ptr<Stages> rec(new Recovery());
    rec->handleAlert(campus2Security);
    rec->handleDispatch(campus2Security);
    rec->handleSecure(campus2Security);

    Response* response = new Response();
    response->handleDispatch(campus2Security);
    Recovery* recovery = new Recovery();
    recovery->handleSecure(campus2Security);
    Detection* detection = new Detection();
    detection->handleAlert(campus2Security);


    campus2Security->setStage(std::move(rec));


    operatorConsole->executeCommand(dispatch);
    operatorConsole->undoLast();



    delete operatorConsole;
    delete emergencyCoordinator;

    return 0;
}