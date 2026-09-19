#ifndef STAGE_H
#define STAGE_H

class CommunicationService;

class Stages {
public:
    virtual ~Stages() = default;

    virtual void handle(CommunicationService* context) = 0;

    // Default rejection methods
    virtual void handleAlert(CommunicationService* context);
    virtual void handleDispatch(CommunicationService* context);
    virtual void handleSecure(CommunicationService* context);
};

#endif