#pragma once

#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog(const std::string& name, int age) : name_(name), age_(age) {}

    void speak() const override;

private:
    std::string name_;
    int age_;
};