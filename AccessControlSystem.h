#ifndef ACCESSCONTROLSYSTEM_H
#define ACCESSCONTROLSYSTEM_H

#include "ResponseComponent.h"
#include "CampusComponent.h"
#include <iostream>

class AccessControlSystem : public ResponseComponent {
public:
    void receiveNotification(const std::string& event) override {
        std::cout << "AccessControlSystem received: " << event << std::endl;
    }
    void triggerEvent(const std::string& event) override {
        std::cout << "AccessControlSystem triggered: " << event << std::endl;
    }
    void lockArea(CampusComponent* area) {
        if (area) {
            std::cout << "AccessControlSystem is locking the area." << std::endl;
            area->lock();
        }
    }
    void unlockArea(CampusComponent* area) {
        if (area) {
            std::cout << "AccessControlSystem is unlocking the area." << std::endl;
            area->unlock();
        }
    }
};

#endif // ACCESSCONTROLSYSTEM_H
