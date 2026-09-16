#ifndef COMMUNICATIONSERVICE_H
#define COMMUNICATIONSERVICE_H

#include "ResponseComponent.h"
#include <iostream>
#include <string>

class CommunicationService : public ResponseComponent {
public:
    void receiveNotification(const std::string& event) override {
        std::cout << "CommunicationService received: " << event << std::endl;
    }
    void triggerEvent(const std::string& event) override {
        std::cout << "CommunicationService triggered: " << event << std::endl;
    }
    void sendAlert(const std::string& msg) {
        std::cout << "CommunicationService sending alert: " << msg << std::endl;
    }
};

#endif // COMMUNICATIONSERVICE_H
