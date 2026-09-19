#ifndef EMERGENCYCOORDINATOR_H
#define EMERGENCYCOORDINATOR_H

class ResponseComponent; // Forward declaration

class EmergencyCoordinator {
public:
    virtual ~EmergencyCoordinator() = default;
    
    // The UML specifies notify(components : ResponseComponent*)
    virtual void notify(ResponseComponent* component) = 0;
    virtual void addComponent(ResponseComponent* component) = 0;
};

#endif // EMERGENCYCOORDINATOR_H
