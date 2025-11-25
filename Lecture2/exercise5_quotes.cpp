// LECTURE 2 - EXERCISE 5: 'char' vs. 'std::string'
//
// This is a HUGE "gotcha" for Python developers.
// In C++, single quotes and double quotes are NOT the same.
//
// 'a' (single quotes) is a 'char' (a single character).
// "a" (double quotes) is a "string literal" (a sequence of characters).
//
// TASK 1: Compile this file.
//   g++ exercise5_quotes.cpp -o exercise5
//
//   ERRORS! You will get two compile-time errors.
//   1. You can't put a multi-character string "Bob" into
//      a 'char' variable (which holds only one character).
//   2. You can't put a 'char' 'B' into a 'std::string' variable
//      using the assignment operator (it's complicated, but
//      it expects a string literal).
//
// TASK 2: Fix the errors.
//   - 'initial' is meant to hold *one* character. Fix line 27.
//   - 'name' is meant to hold a *string*. Fix line 28.
//
// TASK 3: Re-compile and run.
//   g++ exercise5_quotes.cpp -o exercise5
//   ./exercise5
//
//   It should now compile and print the initial and name.

#include <iostream>
#include <string> // We need this for std::string

int main() {
    std::cout << "--- Exercise 5: 'char' vs 'string' ---" << std::endl;

    // --- TASK 2: Fix these two lines! ---
    
    char initial = "B"; // ERROR! 'char' uses single quotes for one character.
    std::string name = 'Bob'; // ERROR! 'std::string' uses double quotes.
    
    // ---
    
    std::cout << "Initial: " << initial << std::endl;
    std::cout << "Name: " << name << std::endl;

    std::cout << "----------------------------------------" << std::endl;
    return 0;
}