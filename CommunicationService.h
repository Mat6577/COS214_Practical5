#ifndef COMMUNICATIONSERVICE_H
#define COMMUNICATIONSERVICE_H

#include "ResponseComponent.h"
#include <iostream>
#include <string>

class CommunicationService : public ResponseComponent {
    std::unique_ptr<Stages> state; 
public:
  virtual ~CommunicationService() {
      state = nullptr;
  }

  void receiveNotification(const std::string &event) override {
    std::cout << "CommunicationService received: " << event << "\n\n";
  }
  void triggerEvent(const std::string &event) override {
    std::cout << "+  CommunicationService triggered: " << event << "\n\n";
    attendIncident();
  }
  void sendAlert(const std::string &msg) {
    std::cout << "CommunicationService sending alert: " << msg << "\n\n";
  }

  /**
   * @brief Used to set current state to new state
   * 
   * @param newState
   * @date 19/09/2026
  */   
  void setStage(std::unique_ptr<Stages> newStage) {
      state = std::move(newStage);
  }

      // Method for changing states
  void changeState() {
      if (state.get()) {
          state->handle(this);          
      } else {
          state = std::unique_ptr<Stages>(new Detection()); 
      }
  }


  // New methods for the template method pattern
  virtual void leaveScene() = 0;

protected:
  virtual void attendIncident() = 0;
};

#endif // COMMUNICATIONSERVICE_H
