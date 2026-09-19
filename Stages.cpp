#include "Stages.h"
#include <iostream>
#include "CommunicationService.h" 

void Stages::handleAlert(CommunicationService* context) {
    std::cout << "[Error] Invalid Operation: Cannot issue alerts in the current state.\n";
}

void Stages::handleDispatch(CommunicationService* context) {
    std::cout << "[Error] Invalid Operation: Cannot dispatch units in the current state.\n";
}

void Stages::handleSecure(CommunicationService* context) {
    std::cout << "[Error] Invalid Operation: Cannot secure the area in the current state.\n";
}