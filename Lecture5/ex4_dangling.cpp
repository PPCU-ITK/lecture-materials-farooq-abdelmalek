#include <iostream>

int main() {
    // 1. Allocate and use memory
    int* p = new int;
    *p = 7;
    
    std::cout << "[Line 8] Value is: " << *p << std::endl;
    
    // 2. Free the memory
    delete p;
    
    // TODO: Fix this.
    // Add one line of code immediately after 'delete p;'
    // that follows "good practice" and will prevent this
    // accidental use (or at least make it crash predictably).
    p = nullptr; // FIX: Set the pointer to nullptr after deallocation.
    
    // ...
    // ... 50 lines of code later ...
    // ...
    
    std::cout << "[Line 18] About to use the pointer again..." << std::endl;
    
    // 3. !! DANGER !!
    // If we hadn't set p to nullptr, this would be a dangling pointer access.
    // However, since we set p = nullptr, the program would now likely
    // crash here with a segmentation fault (accessing address 0).
    
    // To demonstrate the *intent* of the fix without crashing a real program,
    // we'll add a check that *should* be done in real code:
    if (p != nullptr) {
        *p = 10;
        std::cout << "[Line 26] New value is: " << *p << std::endl;
    } else {
        std::cout << "[Line 26] ERROR: Pointer is nullptr. Cannot access memory." << std::endl;
    }
    
    std::cout << "Exercise 4 complete." << std::endl;
    return 0;
}