#include "Stages.h"
#include <iostream>

void Stages::handleAlert(ResponseComponent* context) {
    std::cout << "[Error] Invalid Operation: Cannot issue alerts in the current state.\n";
}

void Stages::handleDispatch(ResponseComponent* context) {
    std::cout << "[Error] Invalid Operation: Cannot dispatch units in the current state.\n";
}

void Stages::handleSecure(ResponseComponent* context) {
    std::cout << "[Error] Invalid Operation: Cannot secure the area in the current state.\n";
}