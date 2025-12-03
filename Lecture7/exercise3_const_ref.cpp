#include <iostream>
#include <vector>

// TODO: Implement this function
// It should take a 'const' reference to a vector
// and print all its elements on a single line.
void printVector(const std::vector<int>& v) {
    // TODO: Use a range-based for loop to print
    // all elements, separated by a space.
    for (int grade : v) {
        std::cout << grade << " ";
    }
    std::cout << std::endl;

    // TODO (Bonus): Try to add 'v.push_back(100);'
    // and see the compiler error.
    // v.push_back(100);  // Error: cannot modify const reference
}


int main() {
    std::vector<int> my_grades = {90, 85, 100, 75};

    std::cout << "My grades are: ";
    // TODO: Call your printVector function
    printVector(my_grades);

    return 0;
}