#ifndef ISSUEALERTCOMMAND_H
#define ISSUEALERTCOMMAND_H

#include "Command.h"
#include "CommunicationService.h"
#include <string>

class IssueAlertCommand : public Command {
private:
    CommunicationService* receiver;
    std::string message;
public:
    IssueAlertCommand(CommunicationService* rec, const std::string& msg);
    ~IssueAlertCommand() {
        delete receiver;
    }
    void execute() override;
    void undo() override;
};

#endif // ISSUEALERTCOMMAND_H
