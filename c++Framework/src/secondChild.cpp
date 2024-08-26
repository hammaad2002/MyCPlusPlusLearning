#include "secondChild.h"
#include <iostream>

void childClassSecond::someFunction(){
    someVariable = std::vector<std::vector<std::vector<double>>>{{{1, 2}, {2, 3}}, {{1}, {2}}};
}

void childClassSecond::newChildFunction(){
    auto myVector = std::any_cast<std::vector<std::vector<std::vector<double>>>>(someVariable);
    for (auto i: myVector){
        std::cout << i.size() << std::endl;
    }
}