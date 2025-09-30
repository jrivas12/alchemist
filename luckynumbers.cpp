#include <iostream>
#include <array>
#include <algorithm>

int main() {
    std::array<int, 10> lucky_numbers = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};
    int lucky = 0;
    bool complete = false;
    while (true) {
        std:: cout << "Enter lottery ticket number (-1 to quit): ";
        std::cin >> lucky;
        if (lucky == -1) {
            break;
        }
        if (std::find(lucky_numbers.begin(), lucky_numbers.end(), lucky) != lucky_numbers.end()) {
            std::cout << "Congratulations! You have a winning ticket!" << std::endl;
            complete = true;
            break;
        } else {
            std::cout << "Sorry, you do not have a winning ticket." << std::endl;
        }
    }
    if (!complete) {
        std::cout << "Exiting program..." << std::endl;
    }
    return 0;
}
