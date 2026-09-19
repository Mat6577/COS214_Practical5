#include "Detection.h"
#include "Response.h"
#include <iostream>
#include "CommunicationService.h" 

void Detection::handleAlert(CommunicationService* context) {
    std::cout << "[Success] Detection State: Executing Alert Sequence...\n";
    std::string eventMsg = "AlertAuthorities";
    context->triggerEvent(eventMsg);
}

/**
 * @brief The handle method for switching states
 * @param context This is a pointer to the object which has a state object/instance
 * 
 * @date 19/09/2026
 */
void Detection::handle(CommunicationService* context) {
    if (!context) {return;}
    handleAlert(context);

    std::unique_ptr<Response> newStage(new Response());
    context->setStage(std::move(newStage));
}