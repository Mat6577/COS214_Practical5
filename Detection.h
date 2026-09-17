#ifndef DETECTION_H
#define DETECTION_H

#include "Stages.h"

class Detection : public Stages {
public:
    void handleAlert(ResponseComponent* context) override;
};

#endif