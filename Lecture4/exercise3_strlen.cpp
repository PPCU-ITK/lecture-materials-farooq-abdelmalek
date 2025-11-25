#include <iostream>

/**
 * Calculates the length of a C-style string.
 * A C-style string is an array of characters
 * terminated by a null character ('\0').
 *
 * @param str A constant pointer to the first
 * character of the string.
 * @return The number of characters in the string,
 * NOT including the null terminator.
 */
int my_strlen(const char* str) {
    // 1. Initialize a counter variable for the length.
    int length = 0;

    // 2. Write a 'while' loop that continues as long
    //    as the character being pointed to (*str)
    //    is NOT the null character ('\0').
    //
    // 3. Inside the loop:
    //    a) Increment your length counter.
    //    b) Increment the pointer 'str' to move to
    //       the next character.

    // TODO: Write your while-loop here.
    // while (*str != '\0') {
    //    ...
    //    ...
    // }


    // 4. Return the final length.
    return length;
}


int main() {
    char greeting[] = "Hello, C++!";

    int len = my_strlen(greeting);

    std::cout << "The string is: " << greeting << std::endl;
    std::cout << "My length is:  " << len << std::endl;
    // Note: The standard library has 'strlen' in <cstring>
    // Let's see if we match!
    // #include <cstring>
    // std::cout << "Std length is: " << strlen(greeting) << std::endl;

    return 0;
}