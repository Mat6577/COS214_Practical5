#ifndef OPERATORCONSOLE_H
#define OPERATORCONSOLE_H

#include "Command.h"
#include <vector>

class OperatorConsole {
private:
    std::vector<Command*> history;
public:
    ~OperatorConsole();
    void executeCommand(Command* c);
    void undoLast();
};

#endif // OPERATORCONSOLE_H
