#ifndef SECUREAREACOMMAND_H
#define SECUREAREACOMMAND_H

#include "Command.h"
#include "AccessControlSystem.h"
#include "CampusComponent.h"

class SecureAreaCommand : public Command {
private:
    AccessControlSystem* receiver;
    CampusComponent* area;
public:
    SecureAreaCommand(AccessControlSystem* rec, CampusComponent* a);
    void execute() override;
    void undo() override;
};

#endif // SECUREAREACOMMAND_H
