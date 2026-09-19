#pragma once 

    // Standard libraries
#include <iostream>

    // Self defined libraries
#include "CommunicationService.h"

class FacilityStaff : public CommunicationService {
private:
public:
    FacilityStaff() = default;
    ~FacilityStaff() = default;
    void attendIncident() override;
    void leaveScene() override;
};

