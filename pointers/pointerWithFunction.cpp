#include <iostream>

/*
Passing by Reference vs Passing by Pointer:

    Passing by Reference: You pass the variable itself. The function can modify the original variable.
    Passing by Pointer  : You pass the address of the variable (using &). The function would then use a 
                          pointer to modify the original variable, and you would need to dereference the pointer.
*/


void varChangerUsingPointer1(int& var) {
    var = 20;
}

void varChangerUsingPointer2(int* var) {
    *var = 20; // Dereferencing pointer to modify the value
}

int main() {
    int var = 10;
    varChangerUsingPointer1(var); // Passing variable directly, no '&' needed
    std::cout << var << std::endl; // Output will be 20

    var = 10;
    varChangerUsingPointer2(&var); // Passing the address of the variable
    std::cout << var << std::endl; // Output will be 20
    
    return 0;

}