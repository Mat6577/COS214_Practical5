#ifndef RESPONSE_H
#define RESPONSE_H

#include "Stages.h"

class Response : public Stages {
public:
    void handle(ResponseComponent* context) override;
    void handleDispatch(ResponseComponent* context) override;
};

#endif      