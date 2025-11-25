#include <iostream>
#include <vector>

void print_scores(const std::vector<int>& scores) {
    std::cout << "[ ";
    for (int s : scores) {
        std::cout << s << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::vector<int> scores = {10, 20, 30, 40, 50};

    std::cout << "Original scores: ";
    print_scores(scores);

    std::cout << "Applying bonus (doubling scores)..." << std::endl;

    // TODO: FIX THIS LOOP
    // Currently, 'score' is a COPY of the data.
    // Changing 'score' does not change the vector.
    for (auto score : scores) {
        score = score * 2;
    }

    std::cout << "After doubling:  ";
    print_scores(scores);

    // Verification
    if (scores[0] == 10) {
        std::cout << "\nFAILED: Scores were not modified." << std::endl;
    } else {
        std::cout << "\nSUCCESS: Scores were modified." << std::endl;
    }

    return 0;
}