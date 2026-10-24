#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

#include <iostream>

template <typename T>
void linearSearchArr(int arrSize, T dataFind, T list[]) {
    for (int i = 0; i < arrSize; i++) {
        if (dataFind == list[i]) {
            std::cout << "Searching is successful.\n";
            return;
        }
    }
    std::cout <<"Searching is unsuccessful. \n";
}

template <typename T>
void binarySearchArr(int arrSize, T dataFind, T list[]) {
    int left = 0;
    int right = arrSize - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (list[mid] == dataFind) {
            std::cout <<"Searching is successful. \n";
            return;
        }
        if (list[mid] < dataFind) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    std::cout <<"Searching is unsuccessful. \n";
}

#endif

