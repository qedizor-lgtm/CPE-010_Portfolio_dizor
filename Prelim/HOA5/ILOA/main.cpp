#include<iostream>
#include<queue>

void display(std::queue<char> copyQ);

int main(){

std::queue<char> myQ;

myQ.push('D');
myQ.push('I');
myQ.push('Z');
myQ.push('O');
myQ.push('R');
myQ.push(' ');
display(myQ);
    
myQ.front();
myQ.back();
std::cout<<myQ.front()<<std::endl;

std::cout<<myQ.back()<<std::endl;




return 0;

}

void display(std::queue<char> copyQ){

    std::queue<char> c = copyQ;

    while  (!c.empty()){
        std::cout<<" " <<c.front();
        c.pop();
    }

    std::cout<<"\n";
    
}

