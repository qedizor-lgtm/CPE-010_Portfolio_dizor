#include <iostream>
#include "queueLL.h"

int main() {
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    enqueue('E', &front, &back);
    checkfrontandback(front, back);
    displayAll(front);

    enqueue('L', &front, &back);
    checkfrontandback(front, back);
    displayAll(front);

    enqueue('I', &front, &back);
    checkfrontandback(front, back);
    displayAll(front);

    dequeue(&front, &back);
    checkfrontandback(front, back);
    displayAll(front);

    return 0;
}

