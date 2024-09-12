#include "Calculator.hpp"

int Calculator::getInput() {
    int first_num;
    int second_num;
    int select_num;

    std::cout << "첫번째 수를 입력하세요: ";
    std::cin >> first_num;
    std::cout << std::endl;

    std::cout << "두번째 수를 입력하세요: ";
    std::cin >> second_num;
    std::cout << std::endl;

    std::cout << "1. 덧셈" << std::endl;
    std::cout << "2. 뺄셈" << std::endl;
    std::cout << "3. 곱셈" << std::endl;
    std::cout << "4. 나눗셈" << std::endl;

    std::cout << "연산을 선택하세요: ";
    std::cin >> select_num;
    std::cout << std::endl;

    switch (select_num) {
        case 1: return this->doSum(first_num, second_num);

        case 2: return this->doSubtract(first_num, second_num);

        case 3: return this->doMultiply(first_num, second_num);

        case 4: return this->doDivide(first_num, second_num);

        default: throw std::invalid_argument("잘못된 연산자입니다.");
    }

    
}

int Calculator::doSum(int a, int b) {
    return a + b;
}

int Calculator::doSubtract(int a, int b) {
    return a - b;
}

int Calculator::doMultiply(int a, int b) {
    return a * b;
}

int Calculator::doDivide(int a, int b) {
    if (b == 0) {
            throw std::invalid_argument("0으로 나눌 수 없습니다.");
        }
    return a / b;
}