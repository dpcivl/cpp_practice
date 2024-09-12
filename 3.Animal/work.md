이번 과제는 **클래스 상속과 다형성**을 연습하는 과제입니다. C++의 객체지향 개념을 확실히 이해할 수 있도록 상속과 가상 함수를 활용한 프로젝트를 진행해봅시다.

### 과제: 동물 소리 시뮬레이션 프로그램

#### 요구사항:
1. **Animal**이라는 **기본 클래스**(base class)를 작성하세요.
   - **name** (이름)과 **age** (나이)를 멤버 변수로 가집니다.
   - **speak()**라는 가상 함수를 작성하여 각 동물의 소리를 출력할 수 있도록 합니다.
   - 생성자와 소멸자를 작성하고, 각 동물의 이름과 나이를 출력합니다.
   
2. **Animal 클래스를 상속받는 세 개의 파생 클래스**(derived class)를 작성하세요.
   - **Dog**: speak() 함수에서 "Woof!"를 출력합니다.
   - **Cat**: speak() 함수에서 "Meow!"를 출력합니다.
   - **Cow**: speak() 함수에서 "Moo!"를 출력합니다.

3. **다형성**을 이용해 **동물의 배열**을 만들고, 반복문을 사용해 각각의 동물이 소리를 내게 하세요.

#### 추가 요구사항:
- `speak()` 함수는 각 동물 클래스에서 **오버라이딩** 되어야 합니다.
- 배열을 통해 각 동물을 관리하고, 동물의 소리와 나이를 출력하세요.
- 메모리 관리를 위해 **동적 할당**을 사용합니다.

### 세부 요구사항:
- 모든 클래스는 `.cpp`와 `.hpp` 파일로 분리하여 작성하세요.
- 동물의 이름과 나이는 **생성자를 통해** 초기화하고, 각 클래스의 생성자에서 이를 처리합니다.

### 예시 코드 구조:
```cpp
#include <iostream>
#include <vector>
#include <string>

// Animal 클래스 (기본 클래스)
class Animal {
protected:
    std::string name;
    int age;

public:
    Animal(const std::string& name, int age) : name(name), age(age) {}
    virtual ~Animal() {}

    // 가상 함수: 각 동물의 소리를 출력
    virtual void speak() const {
        std::cout << name << " makes a sound." << std::endl;
    }

    void showInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

// Dog 클래스 (파생 클래스)
class Dog : public Animal {
public:
    Dog(const std::string& name, int age) : Animal(name, age) {}

    void speak() const override {
        std::cout << name << " says Woof!" << std::endl;
    }
};

// Cat 클래스 (파생 클래스)
class Cat : public Animal {
public:
    Cat(const std::string& name, int age) : Animal(name, age) {}

    void speak() const override {
        std::cout << name << " says Meow!" << std::endl;
    }
};

// Cow 클래스 (파생 클래스)
class Cow : public Animal {
public:
    Cow(const std::string& name, int age) : Animal(name, age) {}

    void speak() const override {
        std::cout << name << " says Moo!" << std::endl;
    }
};

int main() {
    // 동물 객체 배열을 포인터로 생성
    std::vector<Animal*> animals;
    animals.push_back(new Dog("Buddy", 3));
    animals.push_back(new Cat("Whiskers", 2));
    animals.push_back(new Cow("Bessie", 5));

    // 동물의 정보를 출력하고 소리를 내게 함
    for (Animal* animal : animals) {
        animal->showInfo();
        animal->speak();
    }

    // 메모리 해제
    for (Animal* animal : animals) {
        delete animal;
    }

    return 0;
}
```

### 과제 목표:
- 상속과 가상 함수를 사용하여 코드의 확장성을 높이는 방법을 이해합니다.
- 동적 할당을 통해 메모리 관리를 연습합니다.
- 다형성을 통해 하나의 배열에서 여러 파생 클래스 객체를 관리하는 방법을 배웁니다.

프로젝트를 진행한 후, 결과와 소스 코드를 제출해 주세요!