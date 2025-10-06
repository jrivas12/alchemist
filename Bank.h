// Bank.h
#ifndef Bank_H
#define Bank_H

#include <string>
#include <unordered_map>
#include <memory>



class InsufficientFundsException {};

class Account {
protected:
    double balance;

public:
    Account(double balance);
    virtual ~Account() = default;
    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    double getBalance() const;
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(double balance, double interestRate);
    void addInterest();
};

class CheckingAccount : public Account {
private:
    double feePerTransaction;

public:
    CheckingAccount(double balance, double feePerTransaction);
    void deposit(double amount) override;
    void withdraw(double amount) override;
};

std::unordered_map<std::string, std::unique_ptr<Account>> initializeStudents();
Account* login(const std::unordered_map<std::string, std::unique_ptr<Account>>& students, std::string& loggedInUsername, const std::string& correctUsername, const std::string& correctPassword);  // Updated function declaration

void viewAccount(Account* account);
void addMoney(Account* account);
void withdrawMoney(Account* account);

#endif // Bank_H

