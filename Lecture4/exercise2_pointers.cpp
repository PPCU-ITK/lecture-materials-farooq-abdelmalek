#include <iostream>

int main() {
    int data[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(data) / sizeof(data[0]);

    // 1. Create a pointer 'p' that points to the
    //    first element of 'data'.
    int* p = data;

    // 2. Create a "past-the-end" pointer 'p_end'.
    //    This pointer should point to the address
    //    JUST AFTER the last element (data[5]).
    int* p_end = data + n;

    std::cout << "--- Printing with *p operator ---" << std::endl;

    // 3. Write a 'while' loop that continues as
    //    long as 'p' does NOT equal 'p_end'.
    //
    // 4. Inside the loop:
    //    a) Dereference 'p' (using *) to get the value
    //       and print it.
    //    b) Increment the pointer 'p' (using ++) to
    //       move it to the next element.

    // TODO: Write your while-loop here.
    while (p != p_end) {
        std::cout << *p << " ";
        p++;
    }

    std::cout << std::endl;

    return 0;
}