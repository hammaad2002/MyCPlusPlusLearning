#pragma once
#include <vector>
#include <any>

class baseClass{
        
    public:
        baseClass() = default;
        ~baseClass() = default;
        virtual void someFunction();
        void somePrintFunction();
    
    protected:
        std::any someVariable;
};