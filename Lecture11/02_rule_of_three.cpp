#include <iostream>
#include <algorithm> // for std::copy

// ---------------------------------------------------------
// EXERCISE 2: The Rule of Three
//
// GOAL: Implement Dtor, Copy Ctor, and Copy Assignment
//       to safely manage the dynamic array.
// ---------------------------------------------------------

class DynamicArray {
private:
    int* arr;
    int size;

public:
    // Standard Constructor
    DynamicArray(int s) : size(s) {
        arr = new int[size];
        for (int i = 0; i < size; i++) arr[i] = i * 10;
    }

    // 1. DESTRUCTOR
    // TODO: Free the memory pointed to by 'arr'
    ~DynamicArray() {
        // Your code here
    }

    // 2. COPY CONSTRUCTOR
    // TODO: Create a new array of 'size', and copy elements from 'other'
    DynamicArray(const DynamicArray& other) {
        // Your code here
    }

    // 3. COPY ASSIGNMENT OPERATOR
    // TODO: 
    //    a. Check for self-assignment
    //    b. Delete old memory
    //    c. Allocate new memory and copy data
    //    d. Return *this
    DynamicArray& operator=(const DynamicArray& other) {
        // Your code here
        return *this; // Placeholder
    }

    // Helper to print
    void print(const char* name) {
        std::cout << name << ": [";
        if (size > 0) std::cout << arr[0];
        for (int i = 1; i < size; i++) std::cout << ", " << arr[i];
        std::cout << "] @ " << arr << "\n";
    }
    
    // Helper to modify data (to prove deep copy works)
    void set(int index, int val) {
        if (index >= 0 && index < size) arr[index] = val;
    }
};

int main() {
    std::cout << "--- Testing Rule of Three ---\n";

    DynamicArray a(3);
    a.print("A (Original)");

    // Test Copy Constructor
    std::cout << "\n--- Copy Constructor Test ---\n";
    DynamicArray b = a; 
    b.set(0, 999); // Should ONLY change B, not A
    a.print("A (After B modified)");
    b.print("B (Modified)");

    // Test Assignment Operator
    std::cout << "\n--- Assignment Operator Test ---\n";
    DynamicArray c(2);
    c = a; 
    c.print("C (Assigned from A)");

    return 0;
}