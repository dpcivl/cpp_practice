`vector`는 STL의 일부다. 
배열(array)과 유사하지만, 크기를 동적으로 조정할 수 있는 유연성 👍🏼
# 1) `vector`의 주요 특징
- 동적 크기 조정
- 연속된 메모리 할당(배열과 유사한 성격)
- 타입 안전성
- 자동 메모리 관리

# 2) `vector` 사용 예시
```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> myVector; // int 타입을 저장하는 빈 벡터 생성

    // 요소 추가
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    // 인덱스를 사용한 접근
    std::cout << "첫 번째 요소: " << myVector[0] << std::endl;

    // at() 함수를 사용한 접근 (범위 검사 포함)
    std::cout << "두 번째 요소: " << myVector.at(1) << std::endl;

    // 반복자를 사용한 순회
    for(auto it = myVector.begin(); it != myVector.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // range-based for loop 사용
    for(int elem : myVector) {
        std::cout << elem << std::endl;
    }

    return 0;
}

```

# 3) 주의사항
- 큰 용량을 다룰 때는 `reverse()` 메소드를 사용해서, 초기 용량을 사전에 설정하는 것이 좋다. 
- `at()` 함수를 사용해서 접근하면 범위 외의 요소는 건드리지 않는데, 약간의 성능 오버헤드가 발생한다. 