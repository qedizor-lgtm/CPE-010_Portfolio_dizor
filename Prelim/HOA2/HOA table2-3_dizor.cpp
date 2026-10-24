#include <iostream>
#include <string>

class Student {
private:
    std::string studentName;
    int studentAge;

public:
    Student(std::string newName = "robin", int newAge = 22) {
        studentName = std::move(newName);
        studentAge = newAge;
        std::cout << "Constructor Called." << std::endl;
    }

    ~Student() {
        std::cout << "Destructor Called." << std::endl;
    }

    Student(const Student &copyStudent) {
        std::cout << "Copy Constructor Called" << std::endl;
        studentName = copyStudent.studentName;
        studentAge = copyStudent.studentAge;
    }

    void printDetails() {
        std::cout << this->studentName << " " << this->studentAge << std::endl;
    }
};

int main() {
    const int j = 5;
    std::string namesList[j] = {"Carl", "charles", "Sam", "jack", "Colin"};
    int ageList[j] = {15, 16, 18, 19, 16};
    
    Student* studentList = new Student[j];

    for(int i = 0; i < j; i++) {
        studentList[i] = Student(namesList[i], ageList[i]);
    }

    for(int i = 0; i < j; i++) {
        studentList[i].printDetails();
    }

    delete[] studentList;

    return 0;
}

