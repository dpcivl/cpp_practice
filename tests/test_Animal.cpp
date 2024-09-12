#include <gtest/gtest.h>
#include "Dog.hpp"
#include "Cat.hpp"
#include "Cow.hpp"

TEST(AnimalTest, speakTest) {
    Dog dog("Summer", 3);
    Cat cat("Eerly", 2);
    Cow cow("Meoh", 5);

    // StdOut 모킹
    ::testing::internal::CaptureStdout();
    dog.speak();
    std::string dog_output = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(dog_output, "Woof!\n");

    ::testing::internal::CaptureStdout();
    cat.speak();
    std::string cat_output = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(cat_output, "Meow!\n");

    ::testing::internal::CaptureStdout();
    cow.speak();
    std::string cow_output = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(cow_output, "Moo!\n");
}