#ifndef CONCRETEEMERGENCYCOORDINATOR_H
#define CONCRETEEMERGENCYCOORDINATOR_H

#include "EmergencyCoordinator.h"
#include <vector>

class ResponseComponent; // Forward declaration

class ConcreteEmergencyCoordinator : public EmergencyCoordinator {
private:
    std::vector<ResponseComponent*> components;

public:
    ~ConcreteEmergencyCoordinator() {
        components.clear();
    }

    void addComponent(ResponseComponent* component);
    
    void notify(ResponseComponent* component) override;
};

#endif // CONCRETEEMERGENCYCOORDINATOR_H
