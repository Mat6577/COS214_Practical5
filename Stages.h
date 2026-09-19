#ifndef STAGE_H
#define STAGE_H

class ResponseComponent; // Forward declaration to prevent circular dependencies

class Stages {
public:
    virtual ~Stages() = default;

    virtual void handle(ResponseComponent* context) = 0;

    // Default rejection methods
    virtual void handleAlert(ResponseComponent* context);
    virtual void handleDispatch(ResponseComponent* context);
    virtual void handleSecure(ResponseComponent* context);
};

#endif