#include "Student.hpp"

int Student::getTotal() {
    return score_kor + score_math + score_eng;
}

double Student::getAvg() {
    return (score_kor + score_math + score_eng) / 3;
}

void Student::display() {
    std::cout << name << " - Total: " << getTotal() << ", Average: " 
                  << std::fixed << std::setprecision(2) << getAvg() << std::endl;
}

void readStudentsFromFile(const std::string& filename, std::vector<std::unique_ptr<Student>>& students) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string name;
        int korean, math, english;

        if (!(iss >> name >> korean >> math >> english)) {
            throw std::runtime_error("File format error in: " + line);
        }

        students.push_back(std::make_unique<Student>(name, korean, math, english));
    }
}