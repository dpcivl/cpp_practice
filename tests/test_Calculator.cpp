#include <gtest/gtest.h>
#include "Calculator.hpp"

class CalculatorTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }

    Calculator calc;
};

TEST_F(CalculatorTest, InputTest) {
// 입력 테스트는 경계에 있으므로 생략
}

TEST_F(CalculatorTest, SumTest) {

    EXPECT_EQ(calc.doSum(4, 5), 9);
    EXPECT_EQ(calc.doSum(1, -1), 0);
    EXPECT_EQ(calc.doSum(1, -4), -3);
}

TEST_F(CalculatorTest, SubtractTest) {

    EXPECT_EQ(calc.doSubtract(5, 4), 1);
    EXPECT_EQ(calc.doSubtract(1, 1), 0);
    EXPECT_EQ(calc.doSubtract(1, -4), 5);
}

TEST_F(CalculatorTest, MultiplyTest) {

    EXPECT_EQ(calc.doMultiply(2, 3), 6);
    EXPECT_EQ(calc.doMultiply(3, -3), -9);
    EXPECT_EQ(calc.doMultiply(-2, -5), 10);
}

TEST_F(CalculatorTest, DivideTest) {

    EXPECT_EQ(calc.doDivide(6, 3), 2);
    EXPECT_EQ(calc.doDivide(5, 2), 2);
    EXPECT_EQ(calc.doDivide(-4, 2), -2);
    EXPECT_THROW(calc.doDivide(4, 0), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
