#include <iostream>

int main() {
    int power_level = 9000;     // A normal integer on the stack
    
    int* ptr = nullptr;         // A pointer that currently points to NO valid memory

    // Fix: Make the pointer reference an actual variable before dereferencing
    ptr = &power_level;         // Point 'ptr' to the memory address of 'power_level'

    // Now it’s safe to write through the pointer
    *ptr = 9001;                // Change the value stored at that address

    std::cout << "If you see this message, you fixed the crash!" << std::endl;
    std::cout << "Power Level is now: " << power_level << std::endl;

    return 0;
}
