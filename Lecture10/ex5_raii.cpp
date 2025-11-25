#include <iostream>

// A wrapper class that holds a single integer on the heap.
// This demonstrates how C++ classes automate memory management.
class HeapWrapper {
private:
    int* m_ptr; // Raw pointer

public:
    // Constructor: Allocates memory
    HeapWrapper(int value) {
        std::cout << "Allocating memory for value: " << value << std::endl;
        m_ptr = new int(value);
    }

    // TODO: Implement the Destructor
    // It MUST delete the pointer m_ptr to prevent memory leaks.
    // Print "Deleting memory" so we can see it happen.
    ~HeapWrapper() {
        
    }

    void print_value() {
        if (m_ptr) {
            std::cout << "Value is: " << *m_ptr << std::endl;
        }
    }
};

int main() {
    {
        // Create wrapper on the stack
        HeapWrapper w(42);
        w.print_value();
        
        // w goes out of scope here...
        // If your destructor works, it should clean up the 'new int' automatically.
    }
    
    std::cout << "Back in main. If you saw 'Deleting memory', you did it right!" << std::endl;
    return 0;
}