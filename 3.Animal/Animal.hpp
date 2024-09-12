#pragma once
#include <string>
#include <iostream>

class Animal {
public:
    virtual void speak() const {}

    virtual ~Animal() {}
    
    void showInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
    
private:
    std::string name;
    int age;
};