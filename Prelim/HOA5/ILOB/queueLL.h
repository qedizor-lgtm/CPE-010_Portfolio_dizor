#ifndef QUEUELL_H
#define QUEUEULL_H

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


if ((*frontPtr)==nullptr && (*backPtr) == nullptr){
    (*frontPtr) = newNode;
    (*backPtr) = newNode;

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
    if((*frontPtr) == nullptr && (*backPtr) == nullptr){
        std::cout<<"The queue is empty!"<<std::endl;
        return;
     }

    //check if the queue has only 1 node
    if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteNode;
        return;
    }
    //delete the node
    (*frontPtr) = (*frontPtr)->next;
    deleteNode->next = nullptr;
    delete deleteNode;
}


#endif