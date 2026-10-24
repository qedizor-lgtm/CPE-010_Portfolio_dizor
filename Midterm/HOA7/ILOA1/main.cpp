#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    const size_t array_size = 100; 
    int data[array_size];

    for (size_t i = 0; i < array_size; i++) {
        data[i] = std::rand() % 1000; 
    }
    
    std::cout <<"Unsorted Array\n\n";
    for (size_t i = 0; i < array_size; i++) {
        std::cout << data[i] << " ";
        if ((i + 1) % 10 == 0) std::cout << "\n"; 
    }
    std::cout << "\n";

    bubbleSort(data, array_size);

    std::cout <<"Bubble Sort\n\n";
    for (size_t i = 0; i < array_size; i++) {
        std::cout << data[i] << " ";
        if ((i + 1) % 10 == 0) std::cout << "\n"; 
    }
    std::cout << "\n";

    return 0;
}

