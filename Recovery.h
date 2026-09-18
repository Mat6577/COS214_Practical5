#ifndef RECOVERY_H
#define RECOVERY_H

#include "Stages.h"

class Recovery : public Stages {
public:
    void handleSecure(ResponseComponent* context) override;
};

#endif