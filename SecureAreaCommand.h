#ifndef SECUREAREACOMMAND_H
#define SECUREAREACOMMAND_H

#include "Command.h"
#include "AccessControl.h"
#include "CampusComponent.h"

class SecureAreaCommand : public Command {
private:
    // Changed this to AccessControl. I forgot to change it on the UML before sending.
    AccessControl* receiver;
    CampusComponent* area;
public:
    SecureAreaCommand(AccessControl* rec, CampusComponent* a);
    void execute() override;
    void undo() override;
};

#endif // SECUREAREACOMMAND_H
