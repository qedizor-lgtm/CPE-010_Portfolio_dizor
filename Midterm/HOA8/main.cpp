#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "sorting.h" 

void printArray(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
        if ((i + 1) % 10 == 0) std::cout <<std::endl; 
    }
    std::cout <<std::endl;
}

int main() {

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    const int SIZE = 100;
    std::vector<int> originalArray(SIZE);

    for (int i = 0; i < SIZE; i++) {
        originalArray[i] = std::rand() % 500 + 1;
    }

    printArray(originalArray);

    std::vector<int> shellData = originalArray;
    std::vector<int> mergeData = originalArray;
    std::vector<int> quickData = originalArray;

    std::cout << "Shell Sort\n\n";
    shellSort(shellData);
    printArray(shellData);

    std::cout << "Merge Sort\n\n";
    mergeSort(mergeData);
    printArray(mergeData);

    std::cout << "Quick Sort\n\n";
    quickSort(quickData);
    printArray(quickData);

    return 0;
}

