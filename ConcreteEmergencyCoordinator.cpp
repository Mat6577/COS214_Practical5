#include "ConcreteEmergencyCoordinator.h"
#include "ResponseComponent.h"
#include <iostream>

void ConcreteEmergencyCoordinator::addComponent(ResponseComponent *component) {
  if (component) {
    components.push_back(component);
    component->setMediator(this);
  }
}

void ConcreteEmergencyCoordinator::notify(ResponseComponent *component) {
  std::cout << "[Mediator] Received notification from a component. "
               "Coordinating response..."
            << std::endl;

  for (auto *c : components) {
    // Broadcast to all OTHER components
    if (c != component) {
      c->receiveNotification("Mediated coordination event triggered");
    }
  }
}
