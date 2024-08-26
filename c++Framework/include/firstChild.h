#pragma once
#include "baseClass.h"

class childClass: baseClass{

    public:
        childClass() = default;
        ~childClass() = default;
        void someFunction();

        void newChildFunction();

};