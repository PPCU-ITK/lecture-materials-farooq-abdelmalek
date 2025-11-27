#include <iostream>

int main() {
    // 1. A regular integer variable (The House)
    int secret_number = 42;
    
    std::cout << "Original value: " << secret_number << std::endl;

    // TODO 1: Print the memory address of 'secret_number' using the address-of operator (&)
    std::cout << "Address of secret: " << secret_number << std::endl;


    // TODO 2: Declare a pointer variable named 'ptr' (The Mailbox)
    int* ptr = &secret_number;    

    // TODO 3: Use the pointer 'ptr' to change the value of 'secret_number' to 999.
    *ptr = 999;
    

    std::cout << "New value (should be 999): " << secret_number << std::endl;

    return 0;
}