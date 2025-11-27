// LECTURE 2 - EXERCISE 1: THE STATIC CONTRACT
//
// Welcome to C++!
//
// TASK 1: Compile this file.
//   In your terminal, run:
//   g++ exercise1_typing.cpp -o exercise1
//
//   You will get a COMPILE-TIME ERROR. This is the "static contract"
//   at work. Read the error message! It should tell you something
//   like "cannot assign 'const char*' to 'int'".
//
// TASK 2: Fix the error.
//   In C++, 'x' is an 'int' box. It can *only* hold integers.
//   It cannot hold a string like "hello".
//
//   To fix this, simply delete or comment out the broken line.
//
// TASK 3: Add more variables.
//   - Declare a 'double' named 'pi' and set it to 3.14159.
//   - Declare a 'char' named 'initial' and set it to your first initial.
//     (Remember: single quotes for 'char'!)
//   - Declare a 'bool' named 'is_cpp_fun' and set it to true.
//
// TASK 4: Print your new variables.
//   Add 'std::cout' lines to print your new variables.
//
// TASK 5: Re-compile and run.
//   g++ exercise1_typing.cpp -o exercise1
//   ./exercise1
//
//   It should now compile and run, printing your variables.

#include <iostream>

int main() {
    std::cout << "--- Exercise 1: The Static Contract ---" << std::endl;

    int x = 10;
    std::cout << "x is: " << x << std::endl;

    // --- TASK 2: Fix this line ---
    std::cout << "hello" << std::endl; // This is the "Python" way, but it's illegal in C++! , i have done that
    // ---
    
    std::cout << "Now x is: " << x << std::endl;

    // --- TASK 3: Add more variables here ---
    double pi = 3.14159;
    char initial = 'A';          // replace with your own initial
    bool is_cpp_fun = true;
    // ---------------------------------------
    
// --- TASK 4: Print your new variables ---
    std::cout << "pi is: " << pi << std::endl;
    std::cout << "initial is: " << initial << std::endl;
    std::cout << "Is C++ fun? " << is_cpp_fun << std::endl;
    // ----------------------------------------

    std::cout << "---------------------------------------" << std::endl;
    return 0;
}