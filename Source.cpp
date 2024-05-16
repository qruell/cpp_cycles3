#include <iostream>

void drawMirroredTriangle(int height) {
    for (int i = height; i > 0; --i) {
        for (int j = height - i; j > 0; --j) {
            std::cout << "  ";
        }
        for (int j = 0; j < i; ++j) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}

void drawTriangle(int height) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int choice;
    do {
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Draw a triangle" << std::endl;
        std::cout << "2. Draw a mirrored triangle" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cin >> choice;

        switch (choice) {
        case 1:
            int triHeight;
            std::cout << "Enter the height of the triangle: ";
            std::cin >> triHeight;
            drawTriangle(triHeight);
            break;
        case 2:
            int mirroredTriHeight;
            std::cout << "Enter the height of the mirrored triangle: ";
            std::cin >> mirroredTriHeight;
            drawMirroredTriangle(mirroredTriHeight);
            break;
        case 3:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}
