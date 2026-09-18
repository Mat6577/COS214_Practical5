#include "SecureAreaCommand.h"

/**
 * @brief Parameterized Constructor
 * @param receiver A pointer to an instance of the Accesscontrol (The patterns Receiver)
 * @param area A pointer to an instance of the CampusComponent, which is the are where we will be applying the changes
 * 
 * @date 18/09/2026
 */
SecureAreaCommand::SecureAreaCommand(AccessControl *rec, CampusComponent *a)
    : receiver(rec), area(a) {}

/**
 * @brief Performs the receiver's actions
 * 
 * @details The Invoker(OperatorConsole) will call this method through the concrete Command (SecureAreaCommand). The the actions of 
 *          the receiver will be performed
 * @date 18/09/2026
 */
void SecureAreaCommand::execute()
{
    receiver->lockArea(this->area);
}

/**
 * @brief Opposite of execute
 * 
 * @details The Invoker(OperatorConsole) will call this method through the concrete Command (SecureAreaCommand).
 *          The actions of the receiver will be reversed/undone
 * @date 18/09/2026
 */
void SecureAreaCommand::undo()
{
    receiver->unlockArea(this->area);
}
