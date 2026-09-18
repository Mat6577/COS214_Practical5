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
    void addCommand(Command* com);
    void removeCommand(Command* com);
    Command* getCommand(int index);
};

#endif // OPERATORCONSOLE_H
