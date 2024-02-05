#include <iostream>
#include <string>
#include <array>

const int max = 40;
const int courses = 2;

struct Course {
    std::string course_code;
    std::string course_name;
};

struct Grade {
    int mark;
    char the_grade;
};

struct Student {
    std::string registration_number;
    std::string name;
    int age;
    Course course;
    std::array<Grade, courses> grades;
};

char grade(int mark) {
    if (mark > 69) return 'A';
    else if (mark > 59) return 'B';
    else if (mark > 49) return 'C';
    else if (mark > 39) return 'D';
    else return 'E';
}

void info(const Student& student) {
    std::cout << "\nStudent Details:\n";
    std::cout << "Registration Number: " << student.registration_number << "\n";
    std::cout << "Name: " << student.name << "\n";
    std::cout << "Age: " << student.age << "\n";
    std::cout << "Course_code: " << student.course.course_code << "\n";
    std::cout << "Course_name: " << student.course.course_name << "\n";

    for (int j = 0; j < courses; ++j) {
        std::cout << "Grade for Course " << j + 1 << ": " << student.grades[j].the_grade << "\n";
    }
}

int main() {
    int total = 0;
    std::array<Student, max> students;

    while (true) {
        std::cout << "Options:\n1. Add\n2. Edit\n3. Show\n4. Quit\nEnter option: ";
        int option;
        std::cin >> option;

        if (option == 1 && total < max) {
            std::cout << "Enter details for " << total + 1 << ":\n";
            auto& student = students[total];

            std::cout << "Registration Number: ";
            std::cin >> student.registration_number;

            std::cout << "Name: ";
            std::cin >> std::ws;
            std::getline(std::cin, student.name);

            std::cout << "Age: ";
            std::cin >> student.age;

            std::cout << "Course_code: ";
            std::cin >> student.course.course_code;

            std::cout << "Course_name: ";
            std::cin >> std::ws;
            std::getline(std::cin, student.course.course_name);

            for (int j = 0; j < courses; ++j) {
                std::cout << "Enter mark for Course " << j + 1 << ": ";
                std::cin >> student.grades[j].mark;
                student.grades[j].the_grade = grade(student.grades[j].mark);
            }

            ++total;
        } else if (option == 2) {
            std::cout << "Enter the student number you want to edit (1 to " << total << "): ";
            int studentNumber;
            std::cin >> studentNumber;

            if (studentNumber >= 1 && studentNumber <= total) {
                auto& student = students[studentNumber - 1];

                std::cout << "Enter new details for student " << studentNumber << ":\n";
                std::cout << "Registration Number: ";
                std::cin >> student.registration_number;

                std::cout << "Name: ";
                std::cin >> std::ws;
                std::getline(std::cin, student.name);

                std::cout << "Age: ";
                std::cin >> student.age;

                std::cout << "Course_code: ";
                std::cin >> student.course.course_code;

                std::cout << "Course_name: ";
                std::cin >> std::ws;
                std::getline(std::cin, student.course.course_name);
            } else {
                std::cerr << "Invalid.\n";
            }
        } else if (option == 3) {
            std::cout << "Enter the student to display info of (1 to " << total << "): ";
            int studentNumber;
            std::cin >> studentNumber;

            if (studentNumber >= 1 && studentNumber <= total) {
                info(students[studentNumber - 1]);
            } else {
                std::cerr << "Invalid.\n";
            }
        } else if (option == 4) {
            std::cout << "You quit\n";
            break;
        } else {
            std::cerr << "Invalid option.\n";
        }
    }

    return 0;
}

