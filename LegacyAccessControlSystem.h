#pragma once

    // Standard libraries
#include <stdexcept>
#include <iostream>
#include <string>

    // Self defined libraries
#include "CampusComponent.h"

class LegacyAccessControlSystem
{
private:
public:
    LegacyAccessControlSystem() = default;
    ~LegacyAccessControlSystem() = default;

    virtual void lockArea(CampusComponent* area, std::string password);
    virtual void unlockArea(CampusComponent* area, std::string password);
};
