#include <iostream>

#include <iostream>

/**
 * Reverses a C-style string in-place.
 *
 * @param str A pointer to the first character of
 * the string to be reversed.
 */
void reverse_string(char* str) {
    // 1. Create two 'char*' pointers, 'left' and 'right'.
    //    Initialize 'left' to point to the beginning of
    //    the string (str).
    char* left = str;

    // 2. We need to find the end of the string.
    //    If the string is empty (e.g., *str == '\0'),
    //    just return.
    if (!str || !*str) {
        return;
    }

    //    Create 'right' and initialize it to 'str'.
    //    Then, loop 'right' forward until it finds
    //    the null terminator.
    char* right = str;
    // The provided logic for finding the end is:
    // while (*(right + 1) != '\0') {
    //     right++;
    // }
    // A simpler way is to find the null terminator, and then step back one:
    while (*right != '\0') {
        right++;
    }
    right--; // Step back to the last actual character
    
    //    At this point, 'right' points to the *last*
    //    actual character (e.g., 'o' in "Hello").

    // 3. Write a 'while' loop that continues as long
    //    as the 'left' pointer is "to the left of"
    //    the 'right' pointer (i.e., 'left < right').
    //
    // 4. Inside the loop:
    //    a) Create a temporary 'char' variable to
    //       store the value at 'left' (e.g., *left).
    //    b) Copy the value at 'right' into 'left'
    //       (e.g., *left = *right).
    //    c) Copy the value from your temp variable
    //       into 'right' (e.g., *right = temp_char).
    //    d) Increment 'left' (left++).
    //    e) Decrement 'right' (right--).

    // TODO: Write your while-loop here.
    while (left < right) {
        // Swap *left and *right
        char temp = *left; // 4a) Store left value
        *left = *right;    // 4b) Copy right value to left
        *right = temp;     // 4c) Copy stored left value to right

        left++;            // 4d) Move left pointer forward
        right--;           // 4e) Move right pointer backward
    }
}


int main() {
    char name[] = "Bjarne Stroustrup";

    std::cout << "Original:  " << name << std::endl;

    reverse_string(name);

    std::cout << "Reversed: " << name << std::endl;

    char empty[] = "";
    reverse_string(empty);
    std::cout << "Reversed (empty): " << empty << std::endl;

    char single[] = "A";
    reverse_string(single);
    std::cout << "Reversed (single): " << single << std::endl;

    return 0;
}