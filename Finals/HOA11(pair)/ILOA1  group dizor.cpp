#include <iostream>
#include <vector>
#include <chrono>   
#include <iomanip>  
#include <string>

using namespace std;

bool algorithmUnique(const vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j]) {
                return false; 
            }
        }
    }
    return true; 
}

int main() {
    vector<int> inputSizes = {1000, 10000, 100000};

    cout << left << setw(15) << "Input Size" 
         << setw(15) << "Result" 
         << "Execution Speed" << endl;
    cout << string(50, '-') << endl;

    for (int n : inputSizes) {
        vector<int> worstCaseArray;
        worstCaseArray.reserve(n);
        for (int i = 0; i < n; i++) {
            worstCaseArray.push_back(i);
        }

        auto startTime = chrono::high_resolution_clock::now();
        bool isUnique = algorithmUnique(worstCaseArray);
        auto endTime = chrono::high_resolution_clock::now();

        auto durationMs = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();

        cout << left << setw(15) << n 
             << setw(15) << (isUnique ? "True" : "False")
             << durationMs << " ms" << endl;
    }

    return 0;
}

