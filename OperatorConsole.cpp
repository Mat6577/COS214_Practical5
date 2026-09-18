#include "OperatorConsole.h"
#include <iostream>
#include <algorithm>

OperatorConsole::~OperatorConsole() {
    for (Command* c : history) {
        delete c;
    }
    history.clear();
}

void OperatorConsole::executeCommand(Command* c) {
    if (c) {
        c->execute();
        history.push_back(c);
    }
}

void OperatorConsole::undoLast() {
    if (!history.empty()) {
        Command* c = history.back();
        c->undo();
        delete c; 
        history.pop_back();
    } else {
        std::cout << "No commands to undo." << std::endl;
    }
}

void OperatorConsole::addCommand(Command* com) {
    if (com) {
        history.push_back(com);
    }
}

void OperatorConsole::removeCommand(Command* com) {
    auto it = std::find(history.begin(), history.end(), com);
    if (it != history.end()) {
        history.erase(it);
    }
}

Command* OperatorConsole::getCommand(int index) {
    if (index >= 0 && index < static_cast<int>(history.size())) {
        return history[index];
    }
    return nullptr;
}
