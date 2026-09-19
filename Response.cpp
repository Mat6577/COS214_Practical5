#include <iostream>
#include <string>
#include "Response.h"
#include "Recovery.h"
#include "CommunicationService.h" 

void Response::handleDispatch(CommunicationService* context) {
    std::cout << "[Response State] Threat is active. Authorizing dispatch...\n";
    
    std::string eventMsg = "DispatchUnits"; 
    
    context->triggerEvent(eventMsg);
}

/**
 * @brief The handle method for switching states
 * @param context This is a pointer to the object which has a state object/instance
 * 
 * @date 19/09/2026
 */
void Response::handle(CommunicationService* context) {
    if (!context) {return;}

    handleDispatch(context);

    std::unique_ptr<Recovery> newStage(new Recovery());
    context->setStage(std::move(newStage));
}