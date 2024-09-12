#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <memory>
#include <iomanip>

class Student {
public:
    Student (const std::string& student_name, int korean, int math, int english) 
        : name(student_name), score_kor(korean), score_math(math), score_eng(english) {}

    int getTotal();
    double getAvg();
    void display();

private:
    std::string name;
    int score_kor;
    int score_math;
    int score_eng;
};

void readStudentsFromFile(const std::string& filename, std::vector<std::unique_ptr<Student>>& students);