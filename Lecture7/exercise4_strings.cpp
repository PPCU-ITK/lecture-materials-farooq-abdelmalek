#include <iostream>
#include <string>

// TODO: Implement this function
// It should take 'profile_text' by reference (to modify it)
// and 'name' by const reference (to read it).
void addGreeting(/* parameters go here */) {
    // TODO: Append a greeting string (e.g., "Hello, ")
    // and the 'name' to the 'profile_text'.
    // Use the '+' or '+=' operator.
}

int main() {
    std::string userProfile = "User: ";
    std::string userName = "Alice";

    std::cout << "Before: " << userProfile << std::endl;

    // TODO: Call addGreeting
    // addGreeting(userProfile, userName);

    std::cout << "After:  " << userProfile << std::endl;
    // Expected: "After:  User: Hello, Alice!"

    return 0;
}