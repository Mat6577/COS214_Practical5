#ifndef RESPONSE_H
#define RESPONSE_H

#include "Stages.h"
class CommunicationService;


class Response : public Stages {
public:
    void handle(CommunicationService* context) override;
    void handleDispatch(CommunicationService* context) override;
};

#endif      