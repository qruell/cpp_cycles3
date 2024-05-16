#include <iostream>
#include <vector>
#include <map>

struct Item {
    std::string name;
    double price;
};

void selectItem(const std::vector<Item>& items, std::map<std::string, int>& cart) {
    int choice;
    do {
        std::cout << "Select an item:" << std::endl;
        for (int i = 0; i < items.size(); ++i) {
            std::cout << i + 1 << ". " << items[i].name << " - $" << items[i].price << std::endl;
        }
        std::cout << "0. Finish shopping" << std::endl;
        std::cin >> choice;

        if (choice > 0 && choice <= items.size()) {
            std::string itemName = items[choice - 1].name;
            int quantity;
            std::cout << "Enter the quantity of " << itemName << ": ";
            std::cin >> quantity;
            cart[itemName] += quantity;
        }
        else if (choice < 0 || choice > items.size()) {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 0);
}

void calculateTotal(const std::map<std::string, int>& cart, const std::vector<Item>& items, double& total) {
    total = 0;
    for (const auto& item : cart) {
        int index = -1;
        for (int i = 0; i < items.size(); ++i) {
            if (items[i].name == item.first) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            total += items[index].price * item.second;
        }
    }
}

int main() {
    std::vector<Item> items = { {"Christmas Tree", 50.0}, {"Ornaments", 5.0}, {"Lights", 10.0}, {"Santa Hat", 8.0} };
    std::map<std::string, int> cart;
    double total = 0;
    int customerCount = 0;
    double totalRevenue = 0;

    char choice;
    do {
        ++customerCount;
        cart.clear();
        std::cout << "Customer " << customerCount << " shopping:" << std::endl;
        selectItem(items, cart);
        calculateTotal(cart, items, total);
        std::cout << "Total: $" << total << std::endl;
        totalRevenue += total;

        std::cout << "Do you want to serve another customer? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y');

    std::cout << "Total revenue of the store: $" << totalRevenue << std::endl;

    return 0;
}
