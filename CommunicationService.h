#ifndef COMMUNICATIONSERVICE_H
#define COMMUNICATIONSERVICE_H

#include "ResponseComponent.h"
#include <iostream>
#include <string>

class CommunicationService : public ResponseComponent {
public:
    CommunicationService() = default;
    ~CommunicationService() = default;

    void receiveNotification(const std::string& event) override {
        std::cout << "CommunicationService received: " << event << std::endl;
    }
    void triggerEvent(const std::string& event) override {
        std::cout << "CommunicationService triggered: " << event << std::endl;
    }
    void sendAlert(const std::string& msg) {
        std::cout << "CommunicationService sending alert: " << msg << std::endl;
    }

        // New methods for the template method pattern
    virtual void leaveScene() = 0;
protected:
    virtual void assessScene() = 0;
    virtual void attendIncident() = 0;
};

#endif // COMMUNICATIONSERVICE_H
