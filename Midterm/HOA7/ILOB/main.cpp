#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "sorting.h"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    const int ARRAY_SIZE = 101;
    int A[ARRAY_SIZE];

    std::string candidates[] = {
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustín",
        "Deja Jayla Bañaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    for (int i = 0; i < ARRAY_SIZE; i++) {
        A[i] = (std::rand() % 5) + 1; 
    }

    std::cout << "Unsorted Vote Array A\n";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << A[i] << " ";
        if ((i + 1) % 20 == 0) std::cout << "\n";
    }
    std::cout << "\n\n";

    insertionSort(A, ARRAY_SIZE);

    std::cout << "Sorted Vote Array A\n";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << A[i] << " ";
        if ((i + 1) % 20 == 0) std::cout << "\n";
    }
    std::cout << "\n\n";

    int voteCounts[6] = {0}; 
    for (int i = 0; i < ARRAY_SIZE; i++) {
        voteCounts[A[i]]++;
    }

    std::cout << "Vote Count Results \n";
    int maxVotes = 0;
    int winnerID = 1;

    for (int id = 1; id <= 5; id++) {
        std::cout << "Candidate " << id << " (" << candidates[id - 1] 
                  << "): " << voteCounts[id] << " votes\n";
        
        if (voteCounts[id] > maxVotes) {
            maxVotes = voteCounts[id];
            winnerID = id;
        }
    }
    std::cout << "\n";

    std::cout << "WINNING CANDIDATE: " << candidates[winnerID - 1] 
              << " with " << maxVotes << " votes!\n";

    return 0;
}

