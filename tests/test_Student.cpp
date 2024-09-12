#include <gtest/gtest.h>

#include "Student.hpp"

class StudentTest : public ::testing::Test {
protected:
    Student student;

    StudentTest() : student("Peter", 90, 70, 80) {}
};


TEST_F(StudentTest, getTotalTest) {
    EXPECT_EQ(student.getTotal(), 240);
}

TEST_F(StudentTest, getAvgTest) {
    EXPECT_EQ(student.getAvg(), 80);
}

TEST_F(StudentTest, displayTest) {
    ::testing::internal::CaptureStdout();
    student.display();
    std::string student_output = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(student_output, "Peter - Total: 240, Average: 80.00\n");
}


// 테스트 파일을 생성하는 헬퍼 함수
void createTestFile(const std::string& filename, const std::string& content) {
    std::ofstream outfile(filename);
    outfile << content;
    outfile.close();
}
TEST(ReadStudentsFromFileTest, ValidFile) {
    // 테스트용 파일 생성
    std::string filename = "test_students.txt";
    std::string fileContent = "Alice 90 85 88\nBob 70 80 75\nCharlie 100 100 95\n";
    createTestFile(filename, fileContent);

    std::vector<std::unique_ptr<Student>> students;

    ASSERT_NO_THROW(readStudentsFromFile(filename, students));

    ASSERT_EQ(students.size(), 3);

    EXPECT_EQ(students[0]->getTotal(), 263);
    EXPECT_DOUBLE_EQ(students[0]->getAvg(), 87.67);

    EXPECT_EQ(students[1]->getTotal(), 225);
    EXPECT_DOUBLE_EQ(students[1]->getAvg(), 75.00);

    EXPECT_EQ(students[2]->getTotal(), 295);
    EXPECT_DOUBLE_EQ(students[2]->getAvg(), 98.33);
}