#ifndef RECOVERY_H
#define RECOVERY_H

#include "Stages.h"

class Recovery : public Stages {
public:
    void handle(ResponseComponent* context) override;
    void handleSecure(ResponseComponent* context) override;
};

#endif