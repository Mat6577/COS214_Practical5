#include "EmergencyFacade.h"

#include <iostream>

void EmergencyFacade::handleFire(const std::string& issue) {
    AccessControlSystem* control = new AccessControlSystem();
    CampusComponent* area = new CampusComponent();
    SecureAreaCommand* secureArea = new SecureAreaCommand(control, area);

    CommunicationService* staff = new FacilityStaff();
    staff->changeState();  // Detection

    CommunicationService* security = new CampusSecurity();
    security->changeState();  // Detection

    IssueAlertCommand* securityAlert = new IssueAlertCommand(security, issue);

    EmergencyCoordinator* staffToSecurity = new ConcreteEmergencyCoordinator();
    staff->setMediator(staffToSecurity);
    staffToSecurity->addComponent(security);
    staffToSecurity->notify(staff);

    CommunicationService* medical = new MedicalResponders();
    medical->changeState();  // Detection
    IssueAlertCommand* medicalAlert = new IssueAlertCommand(medical, issue);

    EmergencyCoordinator* securityToAll = new ConcreteEmergencyCoordinator();
    securityToAll->addComponent(staff);
    securityToAll->addComponent(control);
    securityToAll->addComponent(medical);

    security->changeState();
    securityToAll->notify(security);

    medical->changeState();
    staff->changeState();

    console->executeCommand(securityAlert);
    console->executeCommand(secureArea);
    console->executeCommand(medicalAlert);

    delete staffToSecurity;
    delete securityToAll;
}

void EmergencyFacade::handleStrike(const std::string &issue)
{
    AccessControlSystem* control = new AccessControlSystem();
    CampusComponent* area = new CampusComponent();
    SecureAreaCommand* secureArea = new SecureAreaCommand(control, area);

    CommunicationService* staff = new FacilityStaff();
    staff->changeState();  // Detection

    CommunicationService* security = new CampusSecurity();
    security->changeState();  // Detection

    IssueAlertCommand* alert = new IssueAlertCommand(security, issue);

    EmergencyCoordinator* staffToSecurity = new ConcreteEmergencyCoordinator();
    staff->setMediator(staffToSecurity);
    staffToSecurity->addComponent(security);

    EmergencyCoordinator* securityToOthers = new ConcreteEmergencyCoordinator();
    security->setMediator(securityToOthers);
    securityToOthers->addComponent(staff);
    securityToOthers->addComponent(control);

    staff->changeState();
    staffToSecurity->notify(staff);

    security->changeState();
    securityToOthers->notify(security);

    staff->changeState();

    console->executeCommand(alert);
    console->executeCommand(secureArea);

    staff->changeState();

    console->undoLast();
    console->undoLast();

    delete staffToSecurity;
    delete securityToOthers;
}
