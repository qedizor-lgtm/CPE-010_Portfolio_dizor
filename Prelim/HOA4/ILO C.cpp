#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() { top = nullptr; }

    void push(char val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            return '\0'; 
        }
        Node* temp = top;
        char poppedValue = temp->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

bool isBalanced(string expr) {
    Stack s;
    
    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }

        else if (ch == ')' || ch == ']' || ch == '}') {

            if (s.isEmpty()) {
                return false;
            }
            
            char openSymbol = s.pop();
            
            if ((ch == ')' && openSymbol != '(') ||
                (ch == ']' && openSymbol != '[') ||
                (ch == '}' && openSymbol != '{')) {
                return false; 
            }
        }

    }
    
    return s.isEmpty();
}

int main() {
    string expressions[] = {
        "(A+B)+(C-D)",
        "((A+B)+(C-D)",
        "((A+B)+[C-D])",
        "((A+B]+[C-D]}"
    };

    for (const string& expr : expressions) {
        cout << "Expression: " << expr << " -> " 
             << (isBalanced(expr) ? "VALID" : "INVALID") << endl;
    }

    return 0;
}
