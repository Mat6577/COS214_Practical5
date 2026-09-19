#include "Recovery.h"
#include <iostream>
#include <string>
#include "CommunicationService.h" 

void Recovery::handleSecure(CommunicationService* context) {
    std::cout << "Recovery stage handling secure event." << std::endl;
}

/**
 * @brief The handle method for switching states
 * @param context This is a pointer to the object which has a state object/instance
 * 
 * @date 19/09/2026
 */
void Recovery::handle(CommunicationService* context) {
    if (!context) {return;}
    handleSecure(context);

    std::unique_ptr<Recovery> newStage(new Recovery());
    context->setStage(std::move(newStage));
}