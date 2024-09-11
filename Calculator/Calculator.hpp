#pragma once
#include <iostream>
#include <stdexcept> 

class Calculator {
public: 
    int getInput();
    int doSum(int a, int b);
    int doSubtract(int a, int b);
    int doMultiply(int a, int b);
    int doDivide(int a, int b);
};