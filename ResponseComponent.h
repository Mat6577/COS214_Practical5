#ifndef RESPONSECOMPONENT_H
#define RESPONSECOMPONENT_H

#include <string>

class EmergencyCoordinator; // Forward declaration

class ResponseComponent {
protected:
    EmergencyCoordinator* mediator;
public:
    virtual ~ResponseComponent() = default;
    virtual void receiveNotification(const std::string& event) = 0;
    virtual void triggerEvent(const std::string& event) = 0;
};

#endif // RESPONSECOMPONENT_H
