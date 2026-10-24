#include <iostream>
using namespace std;

int main() {
    int num1 = 15;
    int num2 = 30;
    
    int temp = num1;
    num1 = num2;
    num2 = temp;
    
    cout << "" << num1 << endl;
    cout << "" << num2 << endl;
    
    return 0;
}

