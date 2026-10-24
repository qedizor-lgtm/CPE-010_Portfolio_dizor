#include <iostream>
#include <vector>
#include <chrono>   
#include <iomanip>  
#include <string>

using namespace std;

double safeLinearPower(double x, int n) {
    double result = 1.0;
    for (int i = 0; i < n; i++) {
        result *= x;
    }
    return result;
}

double brpower(double x, int n) {
    if (n == 0) return 1;
    if (n % 2 != 0) {
        double y = brpower(x, (n - 1) / 2);
        return x * y * y;
    } else {
        double y = brpower(x, n / 2);
        return y * y;
    }
}

int main() {
    vector<int> inputSizes = {1000, 10000, 100000};
    double base = 1.00001; 
    
    // We run each calculation 10,000 times to accumulate measurable time
    const int REPETITIONS = 10000;

    cout << left << setw(18) << "Input Size (n)" 
         << setw(25) << "Linear Speed (rpower)" 
         << "Binary Speed (brpower)" << endl;
    cout << string(65, '-') << endl;

    for (int n : inputSizes) {
        
        // 1. Measure Linear Speed over 10,000 runs
        auto start1 = chrono::high_resolution_clock::now();
        for (int r = 0; r < REPETITIONS; r++) {
            safeLinearPower(base, n);
        }
        auto end1 = chrono::high_resolution_clock::now();
        auto durationLinear = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();

        // 2. Measure Binary Speed over 10,000 runs
        auto start2 = chrono::high_resolution_clock::now();
        for (int r = 0; r < REPETITIONS; r++) {
            brpower(base, n);
        }
        auto end2 = chrono::high_resolution_clock::now();
        auto durationBinary = chrono::duration_cast<chrono::milliseconds>(end2 - start2).count();

        // Format outputs into clear, stable millisecond values
        string linearStr = to_string(durationLinear) + " ms";
        string binaryStr = to_string(durationBinary) + " ms";

        cout << left << setw(18) << n 
             << setw(25) << linearStr
             << binaryStr << endl;
    }

    cout << string(65, '-') << endl;
    return 0;
}

