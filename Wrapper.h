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

        calledMethod = func;
    }


    int execute(inArguments arguments) {

    }


private:
    inArguments args;
    std::function<int(std::vector<int>)> calledMethod;
};


#endif //ENGINEWRAPPER_WRAPPER_H
