#include <iostream>

int main() {
    // 1. Allocate and use memory
    int* p = new int;
    *p = 7;
    
    std::cout << "[Line 8] Value is: " << *p << std::endl;
    
    // 2. Free the memory
    delete p;
    
    // ...
    // ... 50 lines of code later ...
    // ...
    
    std::cout << "[Line 18] About to use the pointer again..." << std::endl;
    
    // 3. !! DANGER !!
    // 'p' is a "dangling pointer". It points to memory that
    // has been freed. Accessing it is Undefined Behavior.
    // This might crash, or it might silently corrupt data.
    *p = 10; 
    std::cout << "[Line 26] New value is: " << *p << std::endl;
    
    // TODO: Fix this.
    // Add one line of code immediately after 'delete p;'
    // that follows "good practice" and will prevent this
    // accidental use (or at least make it crash predictably).

    
    std::cout << "Exercise 4 complete." << std::endl;
    return 0;
}