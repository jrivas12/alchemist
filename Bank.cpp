// Bank.cpp
#include "Bank.h"
#include <iostream> // Add this line

//extern const std::string correctUsername = "Admin";
//extern const std::string correctPassword = "123456";


// Account class implementation
Account::Account(double balance) : balance(balance) {}

void Account::deposit(double amount) {
    balance += amount;
}

void Account::withdraw(double amount) {
    if (amount > balance) {
        throw InsufficientFundsException(); // You might want to define this exception more thoroughly
    }
    balance -= amount;
}

double Account::getBalance() const {
    return balance;
}

// SavingsAccount class implementation
SavingsAccount::SavingsAccount(double balance, double interestRate)
    : Account(balance), interestRate(interestRate) {}

void SavingsAccount::addInterest() {
    double interest = balance * interestRate;
    deposit(interest);
}

// CheckingAccount class implementation
CheckingAccount::CheckingAccount(double balance, double feePerTransaction)
    : Account(balance), feePerTransaction(feePerTransaction) {}

void CheckingAccount::deposit(double amount) {
    Account::deposit(amount - feePerTransaction); // Deduct transaction fee for deposits
}

void CheckingAccount::withdraw(double amount) {
    Account::withdraw(amount + feePerTransaction); // Include transaction fee for withdrawals
}

// Function to initialize student accounts
std::unordered_map<std::string, std::unique_ptr<Account>> initializeStudents() {
    std::unordered_map<std::string, std::unique_ptr<Account>> students;
    
    // Using std::unique_ptr directly instead of std::make_unique
    students["John Garica"] = std::unique_ptr<Account>(new CheckingAccount(1000, 0.02));
    students["Joe Rivas"] = std::unique_ptr<Account>(new SavingsAccount(2000, 0.05));
    students["Martha Rosales"] = std::unique_ptr<Account>(new CheckingAccount(1500, 0.01));
    students["Edward Gaytan"] = std::unique_ptr<Account>(new SavingsAccount(3000, 0.03));
    students["Sarah Chavez"] = std::unique_ptr<Account>(new CheckingAccount(1200, 0.015));
    
    return students; // Complete the return statement
}

Account* login(const std::unordered_map<std::string, std::unique_ptr<Account>>& students, std::string& loggedInUsername, const std::string& correctUsername, const std::string& correctPassword) {
    std::string username;
    std::string password;
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;

    auto it = students.find(username);

    if (it != students.end() && username == correctUsername && password == correctPassword) {
        // Username and password are correct
        std::cout << "Login successful!\n";
        loggedInUsername = username;  // Store the logged-in username
        return it->second.get();
    } else {
        // Incorrect username or password
        std::cout << "Invalid username or password.\n";
        return nullptr;
    }
}

// Function to add money to the account
void addMoney(Account* account) {
    double amount;
    std::cout << "Enter the amount to deposit: ";
    std::cin >> amount;
    account->deposit(amount);
    std::cout << "Deposit successful!\n";
}

// Function to withdraw money from the account
void withdrawMoney(Account* account) {
    double amount;
    std::cout << "Enter the amount to withdraw: ";
    std::cin >> amount;
    try {
        account->withdraw(amount);
        std::cout << "Withdrawal successful!\n";
    } catch (InsufficientFundsException&) {
        std::cout << "Insufficient funds.\n";
    }
}

// Function to view the account balance
void viewAccount(Account* account) {
    std::cout << "Your current balance is: " << account->getBalance() << "\n";
}
