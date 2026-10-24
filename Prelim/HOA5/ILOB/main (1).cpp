#include <iostream>
#include "queueLL.h"

int main(){

    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    enqueue('E', &front, &back);
    std::cout<<  front->data<<""<<back->data<<std::endl;    
    enqueue('L', &front, &back);
    std::cout<<  front->data<<""<<back->data<<std::endl;    
    enqueue('I', &front, &back);
    
    std::cout<<  front->data<<""<<back->data<<std::endl;    

    dequeue(&front, &back);
    std::cout<< front->data <<""<< back->data<<std::endl;

    return 0;
}
