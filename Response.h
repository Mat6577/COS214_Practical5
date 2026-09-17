#ifndef RESPONSE_H
#define RESPONSE_H

#include "Stages.h"

class Response : public Stages {
public:
    void handleDispatch(ResponseComponent* context) override;
};

#endif      