#include <iostream>

void enterBounds(int& lowerBound, int& upperBound) {
    do {
        std::cout << "Enter the lower bound of the range: ";
        std::cin >> lowerBound;
        std::cout << "Enter the upper bound of the range: ";
        std::cin >> upperBound;
        if (lowerBound >= upperBound) {
            std::cout << "Error: Upper bound must be greater than lower bound. Please enter the bounds again." << std::endl;
        }
    } while (lowerBound >= upperBound);
}

int main() {
    int lowerBound, upperBound, number;
    enterBounds(lowerBound, upperBound);

    do {
        std::cout << "Enter a number within the range [" << lowerBound << ", " << upperBound << "]: ";
        std::cin >> number;
        if (number < lowerBound || number > upperBound) {
            std::cout << "Error: The number is not within the specified range. Please try again." << std::endl;
        }
    } while (number < lowerBound || number > upperBound);

    std::cout << "The number " << number << " is within the specified range." << std::endl;

    return 0;
}
