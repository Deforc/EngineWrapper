#ifndef ENGINEWRAPPER_WRAPPER_H
#define ENGINEWRAPPER_WRAPPER_H

#include <vector>
#include <string>
#include <map>
#include <functional>

using inArguments = std::map<std::string, int>;

class Wrapper {
public:
    template<typename Subject, typename ...Arguments>
    Wrapper(Subject* subject, int(Subject::*func)(Arguments...), inArguments const args) {
        this->args = args;
        if (this->args.size() != sizeof... (Arguments))
            throw std::runtime_error("Error: The number of input arguments and function arguments is different");
        calledMethod = [this, subject, func] (std::vector<int> functionArguments) {
            return activateFunction(subject, func, functionArguments, std::make_index_sequence<sizeof ...(Arguments)>{});
        };
    }


    int execute(inArguments arguments) {
        if (arguments.size() != args.size())
        {
            throw std::runtime_error("Error: The number of input arguments exceeds or falls short of the number of declared arguments");
        }
        std::vector<int> argsVector;
        for(auto arg : args)
        {
            if (arguments.find(arg.first) == arguments.end())
                throw std::runtime_error("Error: There is now argument with such name");
            argsVector.push_back(arguments[arg.first]);
        }
        return calledMethod(argsVector);
    }

private:
    template<typename Subject, typename Function, size_t... I>
    int activateFunction(Subject *subject, Function func, std::vector<int> inArgs, std::index_sequence<I...>) {
        return ((subject->*func)(inArgs[I]...));
    }
    inArguments args;
    std::function<int(std::vector<int>)> calledMethod;
};


#endif //ENGINEWRAPPER_WRAPPER_H
