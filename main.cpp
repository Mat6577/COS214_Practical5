#include <iostream>
#include <memory>
#include "ResponseComponent.h"
#include "Detection.h"
#include "Response.h"
#include "Recovery.h"

// A minimal dummy receiver just to test your State pattern output
class DummyReceiver : public ResponseComponent {
public:
    // Added 'const' to match the base class perfectly
    void triggerEvent(const std::string& event) override {
        std::cout << "  -> Receiver caught event: " << event << "\n";
    }

    void receiveNotification(const std::string& event) override {
        std::cout << "  -> Receiver notified: " << event << "\n";
    }
};

int main() {
    // 1. Instantiate the receiver (Context)
    DummyReceiver testReceiver;

    // 2. Initialize with Detection State
    std::cout << "=== INITIALIZING DETECTION STATE ===\n";
    testReceiver.changeStage(std::unique_ptr<Stages>(new Detection()));
    
    // Test routing (Alert should work, Dispatch should fail)
    testReceiver.requestAlert();    
    testReceiver.requestDispatch(); 


    // 3. Transition to Response State
    std::cout << "\n=== TRANSITIONING TO RESPONSE STATE ===\n";
    testReceiver.changeStage(std::unique_ptr<Stages>(new Response()));
    
    // Test routing (Dispatch should work, Secure should fail)
    testReceiver.requestDispatch(); 
    testReceiver.requestSecure();   


    // 4. Transition to Recovery State
    std::cout << "\n=== TRANSITIONING TO RECOVERY STATE ===\n";
    testReceiver.changeStage(std::unique_ptr<Stages>(new Recovery()));
    
    // Test routing (Secure should work, Alert should fail)
    testReceiver.requestSecure();   
    testReceiver.requestAlert();    

    return 0;
}