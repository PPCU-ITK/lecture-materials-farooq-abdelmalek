#include <iostream>
#include <memory>

class BigObject {
public:
    BigObject() { std::cout << "BigObject Created\n"; }
    ~BigObject() { std::cout << "BigObject Destroyed\n"; }
    void say_hello() { std::cout << "Hello from BigObject!\n"; }
};

// This function takes ownership of the pointer.
// It will be responsible for deleting it (automatically) when it returns.
void take_ownership(std::unique_ptr<BigObject> ptr) {
    if (ptr) {
        std::cout << "Inside function: I now own the object.\n";
        ptr->say_hello();
    }
}

int main() {
    // 1. Create a unique_ptr
    std::unique_ptr<BigObject> my_ptr = std::make_unique<BigObject>();
    
    std::cout << "Pointer address before move: " << my_ptr.get() << "\n";

    // 2. TODO: Pass 'my_ptr' to 'take_ownership'.
    // UNCOMMENT the line below. It will fail to compile initially.
    // take_ownership(my_ptr);

    // 3. Fix the error by using std::move()
    // take_ownership(std::move(my_ptr)); 

    // 4. Check the state of the original pointer
    if (my_ptr == nullptr) {
        std::cout << "Main: my_ptr is now empty (nullptr).\n";
    } else {
        std::cout << "Main: my_ptr still owns the object.\n";
    }

    return 0;
}