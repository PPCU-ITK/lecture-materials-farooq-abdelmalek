#include <iostream>

int main() {
    // 1. Allocate an ARRAY of 25 integers
    int* p_arr = new int[25];
    
    p_arr[0] = 1;
    p_arr[24] = 100;
    
    std::cout << "Array allocated." << std::endl;
    
    // 2. !! BUG !!
    // The code is trying to deallocate an ARRAY
    // using the 'delete' operator for a single object.
    // This is Undefined Behavior.
    // delete p_arr; // Original line with the bug
    
    // TODO: Replace the 'delete' line above with the
    // *correct* operator to deallocate an ARRAY.
    delete[] p_arr; // FIX: Use delete[] for memory allocated with new[]
    
    
    std::cout << "Exercise 5 complete." << std::endl;
    return 0;
}