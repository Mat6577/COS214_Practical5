#pragma once 

    // Standard libraries
#include <iostream>

    // Self defined libraries
#include "CommunicationService.h"

class MedicalResponders : public CommunicationService {
private:
public:
    MedicalResponders() = default;
    ~MedicalResponders() = default;

    void assessScene() override;
    void attendIncident() override;
    void leaveScene() override;
};

