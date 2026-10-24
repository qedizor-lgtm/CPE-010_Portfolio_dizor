#ifndef COUNTER_H
#define COUNTER_H

#include <thread>
#include <chrono>

inline int& get_global_counter() {
    static int counter = 0; 
    return counter;
}

inline void add(int value) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    get_global_counter() += value; 
}

#endif

