#include "Detection.h"
#include "ResponseComponent.h"
#include <iostream>

void Detection::handleAlert(ResponseComponent* context) {
    std::cout << "[Success] Detection State: Executing Alert Sequence...\n";
    std::string eventMsg = "AlertAuthorities";
    context->triggerEvent(eventMsg);
}