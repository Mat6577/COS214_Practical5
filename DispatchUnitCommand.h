#ifndef DISPATCHUNITCOMMAND_H
#define DISPATCHUNITCOMMAND_H

#include "Command.h"
#include "ResponseComponent.h"
#include <string>

class DispatchUnitCommand : public Command {
private:
    ResponseComponent* receiver;
    std::string location;
public:
    DispatchUnitCommand(ResponseComponent* rec, const std::string& loc);
    void execute() override;
    void undo() override;
};

#endif // DISPATCHUNITCOMMAND_H
