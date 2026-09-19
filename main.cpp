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
#include "FacilityStaff.h"
#include "EmergencyFacade.h"

void IncidentOne();
void IncidentTwo();

int main() {
    IncidentOne();
    IncidentTwo();

    EmergencyFacade facade;
    facade.handleStrike("Student strike");
    facade.handleFire("One of the lectureHalls is on fire");
    
    return 0;
}

void IncidentOne() {
    OperatorConsole* librarySystem = new OperatorConsole();
    std::string issue = "Student strike";

    // Set up the access control command for the library area
    AccessControlSystem* libraryControl = new AccessControlSystem();  // Receiver
    CampusComponent* library = new CampusComponent();                 // Area being secured
    SecureAreaCommand* LibrarySecurityManagement = new SecureAreaCommand(libraryControl, library);

    // Create the staff receiver, starting in the Detection state
    CommunicationService* libraryStaff = new FacilityStaff();
    libraryStaff->changeState();  // Detection

    // Note: staff does not have a command assigned

    // Create the security receiver, starting in the Detection state
    CommunicationService* librarySecurity = new CampusSecurity();
    librarySecurity->changeState();  // Detection

    // Command that lets security issue an alert about the current situation
    IssueAlertCommand* securityIssueHandler = new IssueAlertCommand(librarySecurity, issue);

    // Mediator connecting staff to security
    EmergencyCoordinator* staffToSecurity = new ConcreteEmergencyCoordinator();
    libraryStaff->setMediator(staffToSecurity);
    staffToSecurity->addComponent(librarySecurity);  // Staff can notify security

    // Mediator connecting security to its own colleagues (staff and access control)
    EmergencyCoordinator* SecurityToOthers = new ConcreteEmergencyCoordinator();
    librarySecurity->setMediator(SecurityToOthers);
    SecurityToOthers->addComponent(libraryStaff);
    SecurityToOthers->addComponent(libraryControl);

    // Advance staff to Response and notify its mediator
    libraryStaff->changeState();
    staffToSecurity->notify(libraryStaff);

    // Advance security to Response and notify its mediator
    librarySecurity->changeState();
    SecurityToOthers->notify(librarySecurity);

    // Staff advances again
    libraryStaff->changeState();

    std::cout << "+++++++++++++++++ Command +++++++++++++++++++\n";
    librarySystem->executeCommand(securityIssueHandler);
    librarySystem->executeCommand(LibrarySecurityManagement);

    std::cout << "\n\nSecurity resolving the issue\n\n";
    libraryStaff->changeState();

    // Undo the two executed commands, most recent first
    librarySystem->undoLast();
    librarySystem->undoLast();

    // Clean up heap-allocated objects
    delete librarySystem;
    delete staffToSecurity;
    delete SecurityToOthers;
}

void IncidentTwo() {
    OperatorConsole* BuildingSystem = new OperatorConsole();
    std::string issue = "One of the lectureHalls is on fire";

    // Set up the access control command for the lecture hall
    AccessControlSystem* BuildingControl = new AccessControlSystem();  // Receiver
    CampusComponent* lectureHall = new CampusComponent();              // Area being secured
    SecureAreaCommand* LectureHallSecurityManagement = new SecureAreaCommand(BuildingControl, lectureHall);

    // Create the staff receiver, starting in the Detection state
    CommunicationService* lectures = new FacilityStaff();
    lectures->changeState();  // Detection

    // Note: staff does not have a command assigned

    // Create the security receiver, starting in the Detection state
    CommunicationService* hallSecurity = new CampusSecurity();
    hallSecurity->changeState();  // Detection

    // Command that lets security issue an alert about the fire
    IssueAlertCommand* securityIssueHandler = new IssueAlertCommand(hallSecurity, issue);

    // Mediator connecting staff to security
    EmergencyCoordinator* lectureToSecurity = new ConcreteEmergencyCoordinator();
    lectures->setMediator(lectureToSecurity);
    lectureToSecurity->addComponent(hallSecurity);  // Staff can notify security

    lectureToSecurity->notify(lectures);  // Notify security of the fire

    // Create the medical responders, starting in the Detection state
    CommunicationService* medicalProfessionals = new MedicalResponders();
    medicalProfessionals->changeState();  // Detection
    IssueAlertCommand* medicalIssueHandler = new IssueAlertCommand(medicalProfessionals, issue);

    // Mediator connecting security to all its observers: staff, building, and medical team
    EmergencyCoordinator* securityToAll = new ConcreteEmergencyCoordinator();
    securityToAll->addComponent(lectures);
    securityToAll->addComponent(BuildingControl);
    securityToAll->addComponent(medicalProfessionals);

    // Advance security state and notify all observers
    hallSecurity->changeState();
    securityToAll->notify(hallSecurity);

    // Advance medical team and staff states
    medicalProfessionals->changeState();
    lectures->changeState();

    // Execute the commands for alerting security, securing the area, and alerting medical
    BuildingSystem->executeCommand(securityIssueHandler);
    BuildingSystem->executeCommand(LectureHallSecurityManagement);
    BuildingSystem->executeCommand(medicalIssueHandler);

    // Clean up heap-allocated objects
    delete BuildingSystem;
    delete lectureToSecurity;
    delete securityToAll;
}