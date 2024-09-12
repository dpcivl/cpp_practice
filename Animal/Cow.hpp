#pragma once

#include "Animal.hpp"

class Cow : public Animal {
public:
    Cow(const std::string& name, int age) : name_(name), age_(age) {}

    void speak() const override;

private:
    std::string name_;
    int age_;
};