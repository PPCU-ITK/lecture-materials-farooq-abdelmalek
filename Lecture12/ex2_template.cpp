#include <iostream>
#include <string>

// EXERCISE 2: Templates

// TODO: Replace this specific function with a Template function.
// It should accept two arguments of generic type T and return T.
// Name it 'add_values'.

int add_values_old(int a, int b) {
    return a + b;
}

// Write your template here:
// template <typename T>
// ...

int main() {
    // 1. Integers
    std::cout << "Int add: " << add_values_old(10, 20) << "\n"; // Change to add_values

    // 2. Doubles
    // UNCOMMENT after writing template
    // std::cout << "Double add: " << add_values(5.5, 2.2) << "\n";

    // 3. Strings
    std::string s1 = "Hello ";
    std::string s2 = "World";
    // UNCOMMENT after writing template
    // std::cout << "String add: " << add_values(s1, s2) << "\n";

    return 0;
}