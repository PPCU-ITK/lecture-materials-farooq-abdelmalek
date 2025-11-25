// LECTURE 2 - EXERCISE 2: THE 'auto' TRAP
//
// The 'auto' keyword is a convenience, NOT dynamic typing.
// The compiler *infers* the type at initialization and
// then locks it in, just as if you had typed it yourself.
//
// TASK 1: Compile this file.
//   g++ exercise2_auto.cpp -o exercise2
//
//   Again, you will get a COMPILE-TIME ERROR.
//   'auto' inferred that 'my_variable' was an 'int' on line 29.
//   The error on line 32 proves that 'my_variable' is *still* an 'int'
//   and cannot be assigned a string.
//
// TASK 2: Fix the code.
//   Comment out the broken line (line 32).
//
// TASK 3: Predict the type.
//   Un-comment the 'auto' variables below (lines 37-39).
//   For each one, in a comment, PREDICT what type the
//   compiler will infer.
//
//   Example:
//   auto p = 3.14; // I predict 'p' will be a 'double'.
//
// TASK 4: Re-compile and run.
//   g++ exercise2_auto.cpp -o exercise2
//   ./exercise2

#include <iostream>
#include <string> // We need this for std::string

int main() {
    std::cout << "--- Exercise 2: The 'auto' Trap ---" << std::endl;

    auto my_variable = 10; // Compiler infers: 'int'
    
    std::cout << "my_variable is: " << my_variable << std::endl;

    // --- TASK 2: Fix this line ---
    my_variable = "now I'm a string!"; // ILLEGAL! my_variable is an 'int' forever.
    // ---
    
    std::cout << "my_variable is now: " << my_variable << std::endl;


    // --- TASK 3: Predict the type for these 'auto' variables ---

    // auto var_a = 3.14f; // I predict 'var_a' will be:
    // auto var_b = "hello world"; // I predict 'var_b' will be: (Hint: it's not std::string!)
    // auto var_c = 'z'; // I predict 'var_c' will be:
    // auto var_d = 1.234; // I predict 'var_d' will be:
    // auto var_e = true; // I predict 'var_e' will be:


    // --- BONUS ---
    // Why is var_b's type what it is? How is it different
    // from this?
    // std::string s = "hello world";
    // auto var_s = s; // I predict 'var_s' will be:

    std::cout << "-----------------------------------" << std::endl;
    return 0;
}