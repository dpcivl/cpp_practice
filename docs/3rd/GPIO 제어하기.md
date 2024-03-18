# 1) gpiochip 인터페이스
- gpioget
- gpioset
- gpioinfo
- gpiodetect

sysfs를 사용해서 gpio를 제어하는 방식은 옛날 방식이라고 한다.

# 1.1> libgpiod 라이브러리
gpiochip 인터페이스를 C/C++ 코드 내에서도 사용할 수 있도록 해주는 것이 libgpiod 라이브러리이다.
`#include <gpiod.hpp>`를 해주면 된다.

