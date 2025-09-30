#include <iostream>
#include "Bank.h"
#include <memory>
using namespace std;

const std::string username = "Admin";
const std::string password = "123456";

std::unordered_map<std::string, std::unique_ptr<Account>> initializeStudents();

int main() {
    std::unordered_map<std::string, std::unique_ptr<Account>> students = initializeStudents();
    std::string loggedInUsername;
    Account* loggedInUser = nullptr;

    while (true) {
        std::cout << "\n----- STC Student Banking Management System -----\n";
        std::cout << "1. Log in\n";
        std::cout << "2. View Account Data\n";
        std::cout << "3. Add money\n";
        std::cout << "4. Withdraw\n";
        std::cout << "5. Log out\n";
        std::cout << "6. Exit\n";

        int choice;
        std::cout << "Enter your choice (1-6): ";
        std::cin >> choice;

        if (choice == 1) {
    if (loggedInUser == nullptr) {
        loggedInUser = login(students, loggedInUsername, username, password);
    } else {
        std::cout << "You are already logged in.\n";
    }

        } else if (choice == 2) {
            if (loggedInUser != nullptr) {
                viewAccount(loggedInUser);
            } else {
                std::cout << "You need to log in first.\n";
            }
        } else if (choice == 3) {
            if (loggedInUser != nullptr) {
                addMoney(loggedInUser);
            } else {
                std::cout << "You need to log in first.\n";
            }
        } else if (choice == 4) {
            if (loggedInUser != nullptr) {
                withdrawMoney(loggedInUser);
            } else {
                std::cout << "You need to log in first.\n";
            }
        } else if (choice == 5) {
            loggedInUser = nullptr;
            loggedInUsername = "";
            std::cout << "Logged out successfully!\n";
        } else if (choice == 6) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    std::cout << "Thank you for using the STC Student Banking Management System!\n";

    return 0;
}