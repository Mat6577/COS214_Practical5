#pragma once

    // Standard libraries
#include <iostream>
#include <string>

    // Self defined libraries
#include "ResponseComponent.h"

class AccessControl : public ResponseComponent {
private:
public:
    AccessControl() = default;
    virtual ~AccessControl() = default;

    // New access control methods
    virtual void lockArea(CampusComponent* area) = 0;
    virtual void unlockArea(CampusComponent* area) = 0;
};
