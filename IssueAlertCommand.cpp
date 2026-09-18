#include "IssueAlertCommand.h"

/**
 * @brief Parameterized Constructor 
 * @param receiver A pointer to an instance of the CommunicationService (The patterns Receiver)
 * @param msg ?
 * 
 * @date 18/09/2026
 */
IssueAlertCommand::IssueAlertCommand(CommunicationService *rec, const std::string &msg)
    : receiver(rec), message(msg) {}

/**
 * @brief Performs the receiver's actions
 * 
 * @details The Invoker(OperatorConsole) will call this method through the concrete Command (SecureAreaCommand). The the actions of 
 *          the receiver will be performed
 * @date 18/09/2026
 */
void IssueAlertCommand::execute()
{
    // receiver->
}

/**
 * @brief Opposite of execute
 * 
 * @details The Invoker(OperatorConsole) will call this method through the concrete Command (SecureAreaCommand).
 *          The actions of the receiver will be reversed/undone
 * @date 18/09/2026
 */
void IssueAlertCommand::undo()
{
    receiver->leaveScene();
}
