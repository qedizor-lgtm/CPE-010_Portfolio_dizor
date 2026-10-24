#ifndef SORTING_H
#define SORTING_H
#include <iostream>
#include <algorithm>

template <typename T>
void bubbleSort(T arr[], size_t arrSize) {
    for (size_t i = 0; i < arrSize; i++) {
        for (size_t j = i + 1; j < arrSize; j++) {
            // Step 3: if A[J] > A[i]
            if (arr[j] > arr[i]) {
                
                std::swap(arr[j], arr[i]);
            }
            
        }
        
    }
}

#endif 

