#include <iostream>

// ---------------------------------------------------------
// EXERCISE 3: The Self-Assignment Trap
//
// GOAL: Fix the operator= to handle (obj = obj) safely.
// ---------------------------------------------------------

class Resource {
public:
    int* value;

    Resource(int v) {
        value = new int(v);
    }

    ~Resource() {
        delete value;
    }

    Resource(const Resource& other) {
        value = new int(*other.value);
    }

    // BUGGY ASSIGNMENT OPERATOR
    Resource& operator=(const Resource& other) {
        std::cout << "Assignment Operator Called...\n";
        
        // STEP 1: We delete our current data
        // (PROBLEM: If other == *this, we just deleted the data we wanted to copy!)
        delete value; 

        // STEP 2: We try to copy from 'other'
        std::cout << "Copying from address: " << other.value << "...\n";
        value = new int(*other.value); 

        return *this;
    }

    void print() {
        if (value) std::cout << "Value: " << *value << "\n";
        else std::cout << "Value: NULL (Corrupted)\n";
    }
};

int main() {
    Resource r1(500);
    
    std::cout << "Initial State:\n";
    r1.print();

    std::cout << "\nPerforming Self-Assignment (r1 = r1)...\n";
    r1 = r1; 

    std::cout << "\nState After Self-Assignment:\n";
    r1.print(); // Expected: Should still be 500. Actual: Crash or Garbage.

    return 0;
}