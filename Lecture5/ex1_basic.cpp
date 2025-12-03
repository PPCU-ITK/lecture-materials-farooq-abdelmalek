#include <iostream>

int main() {
    // TODO 1: Allocate memory for a single integer on the heap.
    // Store the pointer in a variable named 'p_int'.
    int* p_int = new int; 

    // TODO 2: Use the dereference operator (*) to set the value
    // of the integer to 42.
    *p_int = 42;

    // TODO 3: Print the value of the integer using the pointer.
    std::cout << "Value is: " << *p_int << std::endl;

    // TODO 4: Deallocate the memory using the 'delete' operator.
    delete p_int; 

    // TODO 5: (Good Practice) Set the pointer to 'nullptr' after deleting it.
    p_int = nullptr; 

    std::cout << "Exercise 1 complete." << std::endl;
    return 0;
}