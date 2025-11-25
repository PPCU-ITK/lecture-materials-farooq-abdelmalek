#include <iostream>

/**
 * Copies the C-style string from 'source' into
 * the 'destination' buffer.
 *
 * !! DANGER !!
 * This function is inherently unsafe, just like the
 * real 'strcpy'. It assumes 'destination' is large
 * enough to hold 'source'.
 *
 * @param destination Pointer to the destination buffer.
 * @param source Pointer to the source string.
 */
void my_strcpy(char* destination, const char* source) {
    // 1. Write a 'while(true)' loop. We will
    //    copy characters until we hit the '\0'
    //    and then break.
    //
    // 2. Inside the loop:
    //    a) Copy the character from *source to *destination.
    //       (e.g., *destination = *source;)
    //    b) Check if the character you just copied was
    //       the null terminator ('\0').
    //    c) If it was, 'break' from the loop.
    //    d) If it was not, increment both 'destination'
    //       and 'source' pointers.

    // TODO: Write your while-loop here.
    // while (true) {
    //    ...
    //    ...
    //    ...
    //    ...
    // }
}

int main() {
    const char* original_source = "This is the source string.";

    // We have a buffer that is large enough.
    char buffer_safe[100];

    my_strcpy(buffer_safe, original_source);
    std::cout << "Safely copied: " << buffer_safe << std::endl;


    // !! DANGER ZONE !!
    // Now we copy a long string into a tiny buffer.
    char buffer_overflow[10];
    
    // This will compile, but it will write memory
    // past the end of 'buffer_overflow', corrupting
    // whatever is next on the stack!
    
    std::cout << "--- Starting buffer overflow ---" << std::endl;
    my_strcpy(buffer_overflow, original_source);
    std::cout << "Overflowed copy: " << buffer_overflow << std::endl;
    std::cout << "--- Buffer overflow complete ---" << std::endl;

    // The output of this is "undefined behavior".
    // It might print garbage, it might crash, or it
    // might *seem* to work. This is why these
    // bugs are so hard to find.

    return 0;
}