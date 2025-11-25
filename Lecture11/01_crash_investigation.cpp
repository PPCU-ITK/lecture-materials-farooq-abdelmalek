#include <iostream>

// ---------------------------------------------------------
// EXERCISE 1: The Crash Investigation
//
// GOAL: Fix the double-free crash by implementing a 
//       Copy Constructor (Deep Copy).
// ---------------------------------------------------------

class UnsafeBuffer {
public:
    int* data;
    int size;

    // Constructor
    UnsafeBuffer(int s) : size(s) {
        std::cout << "[Allocating " << size << " integers]\n";
        data = new int[size];
        for(int i=0; i<size; i++) data[i] = 7; // Fill with 7s
    }

    // Destructor
    ~UnsafeBuffer() {
        std::cout << "[Deleting Data at " << data << "]\n";
        delete[] data; 
    }

    // TODO: Implement a Copy Constructor here to fix the crash!
    // UnsafeBuffer(const UnsafeBuffer& other) { ... }

};

void triggerCrash() {
    std::cout << "1. Creating original buffer...\n";
    UnsafeBuffer original(10);

    std::cout << "2. Creating copy buffer...\n";
    // THIS LINE TRIGGERS THE DEFAULT SHALLOW COPY
    UnsafeBuffer copy = original; 

    std::cout << "3. 'copy' is about to go out of scope...\n";
} 

int main() {
    std::cout << "--- Exercise 1 Start ---\n";
    
    // Depending on compiler, this might crash immediately 
    // or print garbage values.
    triggerCrash();

    std::cout << "--- Exercise 1 End (If you see this, you fixed it!) ---\n";
    return 0;
}