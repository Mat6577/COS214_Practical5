#pragma once

#include <string>
#include <iostream>
#include "AccessControlSystem.h"
#include "CampusComponent.h"
#include "CampusSecurity.h"
#include "CommunicationService.h"
#include "ConcreteEmergencyCoordinator.h"
#include "EmergencyCoordinator.h"
#include "FacilityStaff.h"
#include "IssueAlertCommand.h"
#include "MedicalResponders.h"
#include "OperatorConsole.h"
#include "SecureAreaCommand.h"

class EmergencyFacade {
private:
    OperatorConsole* console;

public:
    EmergencyFacade() {
        console = new OperatorConsole();
    }

    ~EmergencyFacade() {
        delete console;
    }
    
    void handleStrike(const std::string& issue);
    void handleFire(const std::string& issue);
};
