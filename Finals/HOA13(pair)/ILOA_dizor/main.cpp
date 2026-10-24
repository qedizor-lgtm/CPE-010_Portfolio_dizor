#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include "counter.h"

void log_status(const std::string& message, int current_value) {
    std::cout << std::left << std::setw(30) << message 
              << "Global Counter Value: " << current_value << std::endl;
}

int main() {
    int val1 = 0, val2 = 0, val3 = 0;

    std::cout << "Enter an integer for Thread 1: ";
    std::cin >> val1;
    std::cout << "Enter an integer for Thread 2: ";
    std::cin >> val2;
    std::cout << "Enter an integer for Thread 3: ";
    std::cin >> val3;
    std::cout<<"\n";
    auto start_time = std::chrono::high_resolution_clock::now();
  
    std::thread T1(add, val1);
    std::thread T2(add, val2);
    std::thread T3(add, val3);

    log_status("Initial Display", get_global_counter());

    T1.join();
    log_status("T1.join()", get_global_counter());

    T2.join();
    log_status("T2.join()", get_global_counter());

    T3.join();
    log_status("T3.join()", get_global_counter());

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> total_duration = end_time - start_time;

    return 0;
}

