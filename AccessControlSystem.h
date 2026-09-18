#ifndef ACCESSCONTROLSYSTEM_H
#define ACCESSCONTROLSYSTEM_H

    // Self defined libraries
#include "AccessControl.h"
#include "LegacyAccessControlSystem.h"
#include "ResponseComponent.h"
#include "CampusComponent.h"

    // Standard libraries
#include <iostream>

class AccessControlSystem : public AccessControl, private LegacyAccessControlSystem{
    LegacyAccessControlSystem* legacy;
public:
    void receiveNotification(const std::string& event) override {
        std::cout << "AccessControlSystem received: " << event << std::endl;
    }
    void triggerEvent(const std::string& event) override {
        std::cout << "AccessControlSystem triggered: " << event << std::endl;
    }
    /// @brief Updated these to call the legacy code
    /// @param area A pointer to a campusComponent instance
    void lockArea(CampusComponent* area) {
        if (area) {
            std::cout << "AccessControlSystem is locking the area." << std::endl;
            legacy->lockArea(area, "1234");         // The adapter method calling the adaptee's method
        }
    }
    void unlockArea(CampusComponent* area) {
        if (area) {
            std::cout << "AccessControlSystem is unlocking the area." << std::endl;
            legacy->unlockArea(area, "4321");         // The adapter method calling the adaptee's method
        }
    }
};

#endif // ACCESSCONTROLSYSTEM_H
