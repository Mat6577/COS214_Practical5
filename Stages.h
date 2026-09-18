#ifndef STAGE_H
#define STAGE_H

class ResponseComponent; // Forward declaration to prevent circular dependencies

class Stages {
public:
    virtual ~Stages() = default;

    // Default rejection methods
    virtual void handleAlert(ResponseComponent* context);
    virtual void handleDispatch(ResponseComponent* context);
    virtual void handleSecure(ResponseComponent* context);
};

#endif