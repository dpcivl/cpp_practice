#pragma once
#include <string>
#include <type_traits>
#include <stdexcept>

class BankAccount {
public:
    BankAccount(const std::string& name, double balance)
        : name(name), balance(balance) {}

    ~BankAccount() {}
    double getBalance() const;
    std::string getOwner() const;
    void deposit(double money);
    void withdraw(double money);

private:
    std::string name;
    double balance;
};