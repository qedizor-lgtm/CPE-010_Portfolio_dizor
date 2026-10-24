#include <iostream>
#include <cstdlib>
#include <ctime>
#include "searchingAlgo.h"

const int max_size = 50;

int main() {
    int dataset[max_size];
    srand(time(0));
    
    for (int i = 0; i < max_size; i++) {
        dataset[i] = rand(); 
    }
    
    for (int i = 0; i < max_size; i++) {
        std::cout << dataset[i] << " ";
    }
    std::cout << std::endl;    
    
    int userInput;
    std::cout << "what number to search? ";
    std::cin >> userInput;
    
    linearSearchArr(max_size, userInput, dataset);
    
    for (int i = 0; i < max_size - 1; i++) {
        for (int j = 0; j < max_size - i - 1; j++) {
            if (dataset[j] > dataset[j + 1]) {
                int temp = dataset[j];
                dataset[j] = dataset[j + 1];
                dataset[j + 1] = temp;
            }
        }
    }
    
    binarySearchArr(max_size, userInput, dataset);
    
    return 0;
}

