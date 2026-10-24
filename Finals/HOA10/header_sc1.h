#ifndef DIAGRAPH_H
#define DIAGRAPH_H

#include <iostream>

// Adjacency list node structure

struct adjNode {
    int val;
    int cost;
    adjNode* next;
};

struct graphEdge {
    int start_ver;
    int end_ver;
    int weight;
};

class DiaGraph {
private:
    adjNode* getAdjListNode(int value, int weight, adjNode* head) {
        adjNode* newNode = new adjNode;
        newNode->val = value;
        newNode->cost = weight;
        newNode->next = head;
        return newNode;
    }

public:
    int N;             // number of vertices
    adjNode** head;

    // Constructor
    DiaGraph(graphEdge edges[], int n, int N) {
        this->N = N;
        head = new adjNode*[N]();

        // Construct directed graph by adding edges
        for (int i = 0; i < n; i++) {
            int start_ver = edges[i].start_ver;
            int end_ver = edges[i].end_ver;
            int weight = edges[i].weight;

            adjNode* newNode = getAdjListNode(end_ver, weight, head[start_ver]);
            head[start_ver] = newNode;
        }
    }

    // Destructor to clean up dynamically allocated memory
    ~DiaGraph() {
        for (int i = 0; i < N; i++) {
            adjNode* curr = head[i];
            while (curr != nullptr) {
                adjNode* tmp = curr;
                curr = curr->next;
                delete tmp;
            }
        }
        delete[] head;
    }
};

inline void display_AdjList(adjNode* ptr, int i) {
    while (ptr != nullptr) {
        std::cout << "(" << i << ", " << ptr->val << ", " << ptr->cost << ") ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

#endif

