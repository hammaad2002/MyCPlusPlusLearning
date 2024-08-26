#include "firstChild.h"
#include <iostream>

void childClass::someFunction(){
    someVariable = std::vector<std::vector<double>>{{1, 2, 3}, {4, 5, 6}};
}

void childClass::newChildFunction(){
    auto myVector = std::any_cast<std::vector<std::vector<double>>>(someVariable);
    for (auto i: myVector){
        std::cout << i.size() << std::endl;
    }
}