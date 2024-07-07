#include <iostream>

int main() {
    
    int someVariable = 10;
    int* myPointer;

    //pointer storing address/memory of someVariable where value 10 is stored
    myPointer = &someVariable;

    // the following will print the memory location of someVariable where value 10 is stored
    std::cout << myPointer << std::endl;

    // the following will print the value of someVariable where value 10 is stored
    std::cout << *myPointer << std::endl;

    // for lists we can do the following
    int myArray[] = {1, 2, 3, 4, 5};

    int* arrayPointer;
    int *arrayPointer2;

    // for storing memory address of array we have the option to use or not use the '&' operator
    arrayPointer = myArray;

    // the following will print the memory location of myArray
    std::cout << arrayPointer << std::endl;

    // the element where the above pointer is pointing
    std::cout << *arrayPointer << std::endl;

    // and we can increment using the following way
    arrayPointer++;
    std::cout << *arrayPointer << std::endl;

    // and we do the inverse as well
    arrayPointer--;
    std::cout << *arrayPointer << std::endl;

    // if we use '&' operator then we will need to specify the element location to which to we want to point
    arrayPointer2 = &myArray[0];

    // the element where the above pointer is pointing
    std::cout << *arrayPointer << std::endl;

    // and we can also increment using the following way
    arrayPointer++;
    std::cout << *arrayPointer << std::endl;

    // and we can also do the inverse as well
    arrayPointer--;
    std::cout << *arrayPointer << std::endl;
}