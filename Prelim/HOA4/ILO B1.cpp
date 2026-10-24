#include <iostream>

const size_t maxCap = 100;
int stack[maxCap];
int top = -1, newData, elements;

//prototyping
bool isFull();
bool isEmpty();
void push();
void pop();
void Top();

int main(){
    std::cout << "Enter the number of maximum elements for the new stack (max: 100): ";
    std::cin >> elements;

    if (elements > maxCap) {
        elements = maxCap;
    }

    while(true){
        int choice = 0;
        std::cout << "\nSelect Stack Operation:" << std::endl;
        std::cout << "1. PUSH\n2. POP\n3. VIEW TOP\n4. IS EMPTY?\n5. ISFULL" << std::endl;
        std::cin >> choice;

        switch(choice){
            case 1:
                push();
                break;
            
            case 2:
                pop();
                break;

            case 3:
                Top();
                break;

            case 4:
                if (isEmpty()) {
                    std::cout << "The stack is empty (true)." << std::endl;
                } else {
                    std::cout << "The stack is not empty (false)." << std::endl;
                }
                break;

            case 5:
                if (isFull()) {
                    std::cout << "The stack is full (true)." << std::endl;
                } else {
                    std::cout << "The stack is not full (false)." << std::endl;
                }
                break;

            default:
                std::cout << "Invalid Choice" << std::endl;
                break;
        }
    }
    return 0;
}

bool isEmpty(){
    return (top == -1);
}

bool isFull(){
    return (top >= elements - 1);
}

void push(){
    if (isFull()){
        std::cout << "Stack Overflow! Cannot push more items." << std::endl;
        return;
    }
    std::cout << "What number would you like to add? ";
    std::cin >> newData;
    stack[++top] = newData;
}

void pop(){
    if (isEmpty()){
        std::cout << "Stack Underflow! Cannot pop from an empty stack." << std::endl;
        return;
    }
    std::cout << "Popping: " << stack[top] << std::endl;
    top--;
}

void Top(){
    if(isEmpty()){
        std::cout << "Stack is empty! No top element." << std::endl;
        return;
    }
    std::cout << "The top element is " << stack[top] << std::endl;
}

