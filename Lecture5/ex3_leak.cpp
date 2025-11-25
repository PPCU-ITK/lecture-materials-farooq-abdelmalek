#include <iostream>

/**
 * This function allocates an array of 1000 integers on the heap,
 * does some work, and then returns.
 *
 * IT HAS A MEMORY LEAK!
 */
void leaky_function() {
    std::cout << "leaky_function() starting..." << std::endl;

    // 1. Allocate memory
    int* p = new int[1000];

    // 2. Use the memory
    p[0] = 10;
    p[999] = 100;
    
    // 3. Forget to free the memory
    // The function ends, 'p' is destroyed, but the 1000 ints
    // on the heap are NOT freed. This is a leak.

    // TODO: Add the one line of code needed to fix this memory leak
    // before the function ends.


    std::cout << "leaky_function() ending..." << std::endl;
}


int main() {
    std::cout << "Calling leaky_function..." << std::endl;
    leaky_function();
    std::cout << "leaky_function returned." << std::endl;

    std::cout << "Exercise 3 complete (if you fixed the leak!)." << std::endl;
    return 0;
}