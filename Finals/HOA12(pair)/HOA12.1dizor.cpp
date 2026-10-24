#include <iostream>

const int M = 4;
const int N = 4;

    //4x4 Matrix
int grid[M][N] = {
    {7, 4, 8, 5},
    {1, 3, 7, 6},
    {5, 3, 4, 6},
    {2, 2, 7, 2}
};

int findPaths(int r, int c, int current_sum, const int goal) {
    if (r >= M || c >= N) {
        return 0;
    }

    current_sum += grid[r][c];

    if (current_sum > goal) {
        return 0;
    }

    if (r == M - 1 && c == N - 1) {
        return (current_sum == goal) ? 1 : 0;
    }

    int r_ways = findPaths(r, c + 1, current_sum, goal);
    int d_ways = findPaths(r + 1, c, current_sum, goal);

    return r_ways + d_ways;
}

int main() {
    std::cout << "Grid Layout:\n";
    for (const auto& row : grid) {
        for (int val : row) {
            std::cout << val << "\t";
        }
        std::cout << "\n";
    }

    int total_cost = 0;
    std::cout << "\nEnter desired target cost: ";
    std::cin >> total_cost;

    if (total_cost < 0) {
        std::cout << "Error: Target cost cannot be negative.\n";
        return 1;
    }

    int paths_found = findPaths(0, 0, 0, total_cost);

    std::cout << "\nTarget Cost: " << total_cost << "\n";
    std::cout << "Number of valid paths: " << paths_found << "\n";

    return 0;
}

