#ifndef DETECTION_H
#define DETECTION_H

#include "Stages.h"

class Detection : public Stages {
public:
    void handle(ResponseComponent* context) override;
    void handleAlert(ResponseComponent* context) override;
};

#endif