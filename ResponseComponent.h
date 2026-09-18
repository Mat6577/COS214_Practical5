#ifndef RESPONSECOMPONENT_H
#define RESPONSECOMPONENT_H

#include <string>
#include <memory>

class EmergencyCoordinator; 
class Stages; 
class ResponseComponent {
protected:
    EmergencyCoordinator* mediator;
    std::unique_ptr<Stages> state; 

public:
    virtual ~ResponseComponent() = default;
    
    virtual void receiveNotification(const std::string& event) = 0;
    virtual void triggerEvent(const std::string& event) = 0;
    
    void changeStage(std::unique_ptr<Stages> newStage) {
        state = std::move(newStage);
    }

    void requestAlert();
    void requestDispatch();
    void requestSecure();
};

#endif // RESPONSECOMPONENT_H