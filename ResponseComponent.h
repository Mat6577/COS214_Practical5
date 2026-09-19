#ifndef RESPONSECOMPONENT_H
#define RESPONSECOMPONENT_H

#include <string>
#include <memory>

// class EmergencyCoordinator; 
#include "EmergencyCoordinator.h"
#include "Detection.h"
#include "Recovery.h"
#include "Response.h"
#include "Stages.h" 
class ResponseComponent {
protected:
    EmergencyCoordinator* mediator;
public:
    virtual ~ResponseComponent() {
        mediator = nullptr;
    }
    
    virtual void receiveNotification(const std::string& event) = 0;
    virtual void triggerEvent(const std::string& event) = 0;

    void setMediator(EmergencyCoordinator* m) {
        mediator = m;
    }
};

#endif // RESPONSECOMPONENT_H