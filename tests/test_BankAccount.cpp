#include <gtest/gtest.h>
#include "BankAccount.hpp"

class BankAccountTest : public ::testing::Test {
protected:
    BankAccount account;

    BankAccountTest() : account("Hyo in", 24000.0) {}
    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(BankAccountTest, getBalanceTest) {
    EXPECT_EQ(account.getBalance(), 24000.0);
}

TEST_F(BankAccountTest, getOwnerTest) {
    EXPECT_EQ(account.getOwner(), "Hyo in");
}

TEST_F(BankAccountTest, depositTest) {
    account.deposit(16000.0);

    EXPECT_EQ(account.getBalance(), 40000.0);
}

TEST_F(BankAccountTest, depositTestWhenInputIsNegative) {
    EXPECT_THROW(account.deposit(-12000.0), std::invalid_argument);
}

TEST_F(BankAccountTest, withdrawTest) {
    account.withdraw(12000.0);

    EXPECT_EQ(account.getBalance(), 12000.0);
}

TEST_F(BankAccountTest, withdrawTestWhenExceed) {
    EXPECT_THROW(account.withdraw(25000.0), std::invalid_argument);
}