#ifndef QUEUELL_H
#define QUEUELL_H

#include <iostream>

template <typename T>
class qNode{
    public:
    T data;
    qNode<T>* next;
};

template <typename T>
qNode<T>* new_node(T newData){
    qNode<T>* newNode = new qNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

template<typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr){
    qNode<T>* newNode = new_node(newData);

    if ((*frontPtr) == nullptr){
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
    }
    else {
        (*backPtr)->next = newNode;
        (*backPtr) = newNode;
    }
}

template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr){
    //create temporary mode
    qNode<T>* deleteNode = nullptr;
    deleteNode = (*frontPtr);

    //add a check if queue is already empty
    if((*frontPtr) == nullptr){
        std::cout << "The queue is empty!" << std::endl;
        return;
    }

    //check if the queue has only 1 node
    if((*frontPtr) == (*backPtr)){
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
    }
    else {
        (*frontPtr) = (*frontPtr)->next;
    }

    //delete the node
    deleteNode->next = nullptr;
    delete deleteNode;
}

template <typename T>
void displayAll(qNode<T>* frontPtr){
    if (frontPtr == nullptr){
        std::cout << "The queue is empty!" << std::endl;
        return;
    }
    qNode<T>* current = frontPtr;
    while (current != nullptr){
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
void checkfrontandback(qNode<T>* frontPtr, qNode<T>* backPtr){
    if (frontPtr != nullptr){
        std::cout << frontPtr->data << " ";
    } else {
        std::cout << "NULL ";
    }
    if (backPtr != nullptr){
        std::cout << backPtr->data << std::endl;
    } else {
        std::cout << "NULL" << std::endl;
    }
}

#endif

