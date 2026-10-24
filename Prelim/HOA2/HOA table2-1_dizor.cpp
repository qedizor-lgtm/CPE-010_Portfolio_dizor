#include <iostream>
#include <string>

class Student {
private:
    std::string studentName;
    int studentAge;

public:
	
	//constructor
	
    Student(std::string newName = "robin", int newAge = 22) {
        studentName = std::move(newName);
        studentAge = newAge;
        std::cout << "Constructor Called." << std::endl;
    }

    //deconstructor
    
    ~Student() {
        std::cout << "Destructor Called." << std::endl;
    }
    
    //Copy Constructor
    
    Student(const Student &copyStudent) {
        std::cout << "Copy Constructor Called" << std::endl;
        studentName = copyStudent.studentName;
        studentAge = copyStudent.studentAge;
    }
    
    //Display Attributes
    void printDetails() {
        std::cout << this->studentName << " " << this->studentAge << std::endl;
    }
};

int main() {
    const size_t j = 5;
    std::string namesList[j] = {"Carl", "charles", "Sam", "jack", "Colin"};
    int ageList[j] = {15, 16, 18, 19, 16};
    
    Student studentList[j];

    for(size_t i = 0; i < j; i++) {
        studentList[i] = Student(namesList[i], ageList[i]);
    }

    for(size_t i = 0; i < j; i++) {
        studentList[i].printDetails();
    }

    return 0;
}

