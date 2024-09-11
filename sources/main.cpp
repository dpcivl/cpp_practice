#include "main.h"

int main() {
    Calculator calc;

    auto result = calc.getInput();

    std::cout << "계산값은 " << result << "입니다. " << std::endl;
}