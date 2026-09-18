#ifndef RESPONSECOMPONENT_H
#define RESPONSECOMPONENT_H

#include <string>
#include <memory>

class EmergencyCoordinator; 
#include "Stages.h" 
class ResponseComponent {
protected:
    EmergencyCoordinator* mediator;
    std::unique_ptr<Stages> state; 

public:
    virtual ~ResponseComponent() {
        delete mediator;
        state = nullptr;
    }
    
    virtual void receiveNotification(const std::string& event) = 0;
    virtual void triggerEvent(const std::string& event) = 0;
    
    void changeStage(std::unique_ptr<Stages> newStage) {
        state = std::move(newStage);
    }

    void setMediator(EmergencyCoordinator* m) {
        mediator = m;
    }

    void requestAlert();
    void requestDispatch();
    void requestSecure();
};

#endif // RESPONSECOMPONENT_H