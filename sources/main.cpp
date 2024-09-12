#include "main.h"

int main() {
    // Calculator calc;

    // auto result = calc.getInput();

    // std::cout << "계산값은 " << result << "입니다. " << std::endl;

    // // BankAccount 객체 생성 시, 소유자와 초기 잔액을 전달
    // BankAccount account("Alice", 1000.0);

    // std::cout << "Owner: " << account.getOwner() << std::endl;
    // std::cout << "Balance: $" << account.getBalance() << std::endl;

    // account.deposit(500.0);
    // std::cout << "After deposit: $" << account.getBalance() << std::endl;

    // account.withdraw(300.0);
    // std::cout << "After withdrawal: $" << account.getBalance() << std::endl;

    // account.withdraw(1500.0);  // 잔액보다 큰 금액 출금 시도
    // std::cout << "Final balance: $" << account.getBalance() << std::endl;

    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Dog>("Buddy", 3));
    animals.push_back(std::make_unique<Cat>("Whiskers", 2));
    animals.push_back(std::make_unique<Cow>("Bessie", 5));

    // 반복문을 통해 각 동물의 speak() 호출
    for (const auto& animal : animals) {
        animal->speak();  // unique_ptr로 관리하는 객체의 메서드를 호출
    }
    
    return 0;
}
