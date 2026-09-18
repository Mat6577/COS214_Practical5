#include <iostream>
#include <string>
#include "ResponseComponent.h"
#include "Response.h"

void Response::handleDispatch(ResponseComponent* context) {
    std::cout << "[Response State] Threat is active. Authorizing dispatch...\n";
    
    std::string eventMsg = "DispatchUnits"; 
    
    context->triggerEvent(eventMsg);
}
