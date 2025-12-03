#include <iostream>
#include <memory> // Required for std::unique_ptr
#include <stdexcept>

// A dummy class to help us visualize creation and destruction
class IntegerWrapper {
    int value;
public:
    IntegerWrapper(int v) : value(v) {
        std::cout << "Constructed IntegerWrapper(" << value << ")\n";
    }
    ~IntegerWrapper() {
        std::cout << "Destructed IntegerWrapper(" << value << ")\n";
    }
    int get() const { return value; }
};

void risky_operation() {
    throw std::runtime_error("Something went wrong!");
}

int main() {
    try {
        std::cout << "Allocating memory...\n";
        
        // TODO: Replace the following two lines with std::unique_ptr
        
        std::unique_ptr<IntegerWrapper> smart_ptr(new IntegerWrapper(42));
        
        // This simulates a function that might fail
        risky_operation();

        std::cout << "Using value: " << smart_ptr->get() << "\n";

        // TODO: If you use unique_ptr, you won't need this explicit delete
        // delete raw_ptr; 
        std::cout << "Memory successfully freed.\n";

    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
        std::cout << "Exiting main...\n";
        // No need to manually free memory when using unique_ptr
    }

    // If successful, you should see "Destructed IntegerWrapper" printed above.
    return 0;
}