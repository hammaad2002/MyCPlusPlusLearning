#include "firstChild.h"
#include "secondChild.h"
#include <iostream>

int main(){
    std::cout << "Testing\n";

    childClass object;
    object.someFunction();
    object.newChildFunction();

    childClassSecond objectSecond;
    objectSecond.someFunction();
    objectSecond.newChildFunction();

    return 0;
}