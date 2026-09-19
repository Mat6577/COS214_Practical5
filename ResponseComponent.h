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
    std::unique_ptr<Stages> state; 

public:
    ResponseComponent() {
        state = std::unique_ptr<Detection>();
    }
    virtual ~ResponseComponent() {
        mediator = nullptr;
        state = nullptr;
    }
    
    virtual void receiveNotification(const std::string& event) = 0;
    virtual void triggerEvent(const std::string& event) = 0;
    
    void setStage(std::unique_ptr<Stages> newStage) {
        state = std::move(newStage);
    }

        // Method for changing states
    void changeState() {
        if (state.get()) {
            state->handle(this);     
            state->handleAlert(this);
            state->handleDispatch(this);       
        } else {
            state = std::unique_ptr<Stages>(new Detection()); 
        }
    }

    void setMediator(EmergencyCoordinator* m) {
        mediator = m;
    }

        // Moved the function definitions to the .h file for testing of ff
    void requestAlert() {
        if (state) {
            state->handleAlert(this);
        }
    }

    void requestDispatch() {
        if (state) {
            state->handleDispatch(this);
        }
    }

    void requestSecure() {
        if (state) {
            state->handleSecure(this);
        }
    }
};

#endif // RESPONSECOMPONENT_H