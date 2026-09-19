#ifndef RECOVERY_H
#define RECOVERY_H

#include "Stages.h"
class CommunicationService;


class Recovery : public Stages {
public:
    void handle(CommunicationService* context) override;
    void handleSecure(CommunicationService* context) override;
};

#endif