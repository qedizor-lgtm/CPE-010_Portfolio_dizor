#include <iostream>

using namespace std;

//adjacency list
struct adjNode {
    int val, cost;
    adjNode* next;
};

//store edges
struct graphEdge {
    int start_ver, end_ver, weight;
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
    int N; 
    adjNode** head; 

    // Constructor
    DiaGraph(graphEdge edges[], int n, int N) {
        head = new adjNode*[N]();
        this->N = N;

        for (int i = 0; i < N; ++i) {
            head[i] = nullptr;
        }

        for (unsigned i = 0; i < n; i++) {
            int start_ver = edges[i].start_ver;
            int end_ver = edges[i].end_ver;
            int weight = edges[i].weight;

            adjNode* newNode = getAdjListNode(end_ver, weight, head[start_ver]);

            head[start_ver] = newNode;
        }
    }

    // Destructor
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

void display_AdjList(adjNode* ptr, int i)
{
    while (ptr != nullptr) {
        std::cout << "(" << i << ", " << ptr->val
                  << ", " << ptr->cost << ") ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

int main()
{
    // graph edges array.
    graphEdge edges[] = {
        {0,1,2}, {0,2,4}, {1,4,3}, {2,3,2}, {3,1,4}, {4,3,3}
    };
    
    int N = 6; //number of vertices in the graph
    
    //number of edges
    int n = sizeof(edges) / sizeof(edges[0]);
    
    // cons graph
    DiaGraph diagraph(edges, n, N);
    
 
    std::cout << "    Graph adjacency list " << std::endl 
              << "start_vertex, end_vertex, weight: \n" << std::endl;
              
    for (int i = 0; i < N; i++)
    {
        // display adjacent vertices of vertex i
        display_AdjList(diagraph.head[i], i);
    }
    
    return 0;
}


