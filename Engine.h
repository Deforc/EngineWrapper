#ifndef ENGINEWRAPPER_ENGINE_H
#define ENGINEWRAPPER_ENGINE_H

#include "Wrapper.h"

class Engine {
public:
    void registerCommand(Wrapper* wrapper, const std::string & command) {
        if(commands.find(command) != commands.end())
        {
            throw std::runtime_error("Error: This command is already registered");
        }
        commands.insert({command, wrapper});
    }

    int execute(const std::string& command, inArguments const args) {
        if (commands.find(command) == commands.end())
        {
            throw std::runtime_error("Error: This command has n`t been registered");
        }
        return commands[command]->execute(args);
    }
private:
    std::map<std::string, Wrapper*> commands;
};


#endif //ENGINEWRAPPER_ENGINE_H
