#include "BankAccount.hpp"

double BankAccount::getBalance() const{
        return balance;
    }

std::string BankAccount::getOwner() const {
    return name;
}

void BankAccount::deposit(double money) {
    if (money >= 0) balance =  money + balance;
    else throw std::invalid_argument("입력값이 음수입니다.");
}

void BankAccount::withdraw(double money) {
    if (money >= 0) balance = balance - money;
    else throw std::invalid_argument("입력값이 음수입니다.");

    if (balance < 0) {
        throw std::invalid_argument("잔액보다 많은 금액 출금");
    }
}