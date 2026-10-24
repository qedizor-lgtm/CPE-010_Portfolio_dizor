#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <algorithm>
#include <climits>

void find_partial_min(const std::vector<int>& arr, int start, int end, int& output_min) {
    int local_min = INT_MAX;
    for (int i = start; i < end; ++i) {
        if (arr[i] < local_min) {
            local_min = arr[i];
        }
    }
    output_min = local_min;
}

void evaluate_performance(int workload_size) {
    std::vector<int> data_pool(workload_size);
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(-500000, 500000);
    
    for (int i = 0; i < workload_size; ++i) {
        data_pool[i] = distribution(generator);
    }

    std::cout << "Elements checked: " << workload_size << std::endl;
    std::cout << "Search boundary: " << INT_MAX << std::endl;
    std::cout << "\n" << std::endl;

    auto seq_start = std::chrono::high_resolution_clock::now();
    
    int sequential_minimum = INT_MAX;
    for (int i = 0; i < workload_size; ++i) {
        if (data_pool[i] < sequential_minimum) {
            sequential_minimum = data_pool[i];
        }
    }
    
    auto seq_end = std::chrono::high_resolution_clock::now();
    auto seq_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(seq_end - seq_start).count() / 1000.0;

    std::cout << "Sequential result found: " << sequential_minimum << std::endl;
    std::cout << "Sequential processing duration: " << seq_duration << " microseconds" << std::endl;
    std::cout << std::endl;

    auto parallel_start = std::chrono::high_resolution_clock::now();

    const int THREAD_POOL_SIZE = 4;
    std::thread worker_pool[THREAD_POOL_SIZE];
    int intermediate_mins[THREAD_POOL_SIZE] = { INT_MAX, INT_MAX, INT_MAX, INT_MAX };
    
    int segment_width = workload_size / THREAD_POOL_SIZE;

    for (int i = 0; i < THREAD_POOL_SIZE; ++i) {
        int left_boundary = i * segment_width;
        int right_boundary = (i == THREAD_POOL_SIZE - 1) ? workload_size : (left_boundary + segment_width);
        
        worker_pool[i] = std::thread(find_partial_min, 
                                     std::ref(data_pool), 
                                     left_boundary, 
                                     right_boundary, 
                                     std::ref(intermediate_mins[i]));
    }

    int final_parallel_minimum = INT_MAX;
    for (int i = 0; i < THREAD_POOL_SIZE; ++i) {
        worker_pool[i].join();
        if (intermediate_mins[i] < final_parallel_minimum) {
            final_parallel_minimum = intermediate_mins[i];
        }
    }

    auto parallel_end = std::chrono::high_resolution_clock::now();
    auto parallel_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(parallel_end - parallel_start).count() / 1000.0;

    std::cout << "Parallel pool result: " << final_parallel_minimum << std::endl;
    std::cout << "Parallel pool duration: " << parallel_duration << " microseconds" << std::endl;
    std::cout << "\n" << std::endl;
}

int main() {
    evaluate_performance(5000);
    evaluate_performance(2000000);
    return 0;
}

