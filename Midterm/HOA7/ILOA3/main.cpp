#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

void generateRandomArray(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = std::rand() % 1000; 
    }
}

void printArray(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
        if ((i + 1) % 10 == 0) std::cout << "\n";
    }
    std::cout << "\n";
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    const size_t array_size = 100;
    int data[array_size];

    generateRandomArray(data, array_size);
    std::cout <<"Preparation Task: Unsorted Array\n";
    printArray(data, array_size);
    bubbleSort(data, array_size);
    std::cout << "After Bubble Sort\n";
    printArray(data, array_size);

    generateRandomArray(data, array_size);
    std::cout <<"Preparation Task: Unsorted Array\n";
    printArray(data, array_size);
    selectionSort(data, static_cast<int>(array_size));
    std::cout <<" After Selection Sort\n";
    printArray(data, array_size);

    generateRandomArray(data, array_size);
    std::cout <<"Preparation Task: Unsorted Array\n";
    printArray(data, array_size);
    insertionSort(data, static_cast<int>(array_size));
    std::cout <<"After Insertion Sort\n";
    printArray(data, array_size);

    return 0;
}

