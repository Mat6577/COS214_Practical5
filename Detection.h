#ifndef DETECTION_H
#define DETECTION_H

#include "Stages.h"
class CommunicationService;

class Detection : public Stages {
public:
    void handle(CommunicationService* context) override;
    void handleAlert(CommunicationService* context) override;
};

#endif