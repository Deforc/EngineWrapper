#include <iostream>
#include "Subject.h"
#include "Wrapper.h"
#include "Engine.h"
int main() {
    Subject subject;

    Wrapper wrapper1(&subject, &Subject::f1, {{"arg1", 0}, {"arg2", 0}, {"arg3", 0}});
    Wrapper wrapper2(&subject, &Subject::f2, {{"arg1", 0}});
    Wrapper wrapper3(&subject, &Subject::f3, {{"arg1", 0}, {"arg2", 0}});

    Engine engine;
    engine.registerCommand(&wrapper3, "command1");
    engine.registerCommand(&wrapper1, "command2");
    engine.registerCommand(&wrapper2, "command3");
    std::cout << engine.execute("command1", {{"arg1", 2}, {"arg2", 1}}) << std::endl;
    std::cout << engine.execute("command2", {{"arg1", 3}, {"arg2", 2}, {"arg3", 1}}) << std::endl;
    std::cout << engine.execute("command3", {{"arg1", 2}}) << std::endl;

}
