#pragma once 

    // Standard libraries
#include <iostream>

    // Self defined libraries
#include "CommunicationService.h"

class CampusSecurity : public CommunicationService {
private:
public:
    CampusSecurity() = default;
    ~CampusSecurity() = default;

    void attendIncident() override;
    void leaveScene() override;
};

