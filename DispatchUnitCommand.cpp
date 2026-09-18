#include "DispatchUnitCommand.h"
#include <iostream>
/**
 * @brief Parameterized Constructor
 * @param rece A pointer to an instance of the Accesscontrol (The patterns Receiver)
 * @param loc the locations that is affected by the command
 * 
 * @date 18/09/2026
 */
DispatchUnitCommand::DispatchUnitCommand(ResponseComponent *rec, const std::string &loc)
   : receiver(rec), location(loc)  {}

/**
 * @brief Performs the receiver's actions
 *
 * @details The Invoker(OperatorConsole) will call this method through the concrete Command (DispatchUnitCommand). The the actions of
 *          the receiver will be performed
 * @date 18/09/2026
 */
void DispatchUnitCommand::execute()
{
    std::cout << "Executing DispatchUnitCommand to location: " << this->location << std::endl;
    if (receiver) {
        receiver->triggerEvent(this->location);
    }
}

/**
 * @brief Opposite of execute
 * 
 * @details The Invoker(OperatorConsole) will call this method through the concrete Command (DispatchUnitCommand).
 *          The actions of the receiver will be reversed/undone
 * @date 18/09/2026
 */
void DispatchUnitCommand::undo()
{
    std::cout << "Undoing DispatchUnitCommand to location: " << this->location << std::endl;
    if (receiver) {
        receiver->receiveNotification(this->location);
    }
}
