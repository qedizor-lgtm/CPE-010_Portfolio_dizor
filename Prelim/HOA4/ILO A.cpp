#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> characters;

    characters.push("issa rei");
    characters.push("sydney sweedney");
    characters.push("hillary clinton ");
    characters.push("paige");
    characters.pop();

    cout << characters.top();

    cout<< characters.empty();
    return 0;
}

