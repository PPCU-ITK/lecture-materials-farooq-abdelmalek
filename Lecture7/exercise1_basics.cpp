#include <iostream>

int main() {
    // 1. Create an int variable named 'original' with value 10
    int original = 10;
    std::cout << "Original: " << original << std::endl;

    // 2. Create an int reference 'alias' initialized with 'original'
    int& alias = original;

    // 3. Modify 'original' to 20
    original = 20;

    // 4. Print both 'original' and 'alias'
    std::cout << "--- After modifying original ---" << std::endl;
    std::cout << "Original: " << original << std::endl;
    std::cout << "Alias:    " << alias << std::endl;

    // 5. Modify 'alias' to 30
    // TODO: Your code here
    alias = 30;

    // 6. Print both 'original' and 'alias' again
    std::cout << "--- After modifying alias ---" << std::endl;
    // TODO: Your code here
    std::cout << "Original: " << original << std::endl;
    std::cout << "Alias:    " << alias << std::endl;
    return 0;
}