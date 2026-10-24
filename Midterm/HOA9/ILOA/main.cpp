#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    char data;
    TreeNode* leftChild;   
    TreeNode* nextSibling; 

    TreeNode(char val) {
        data = val;
        leftChild = nullptr;
        nextSibling = nullptr;
    }
};

void addChild(TreeNode* parent, TreeNode* child) {
    if (!parent || !child) return;
    
    if (!parent->leftChild) {
        parent->leftChild = child;
    } else {
        TreeNode* current = parent->leftChild;
        while (current->nextSibling) {
            current = current->nextSibling;
        }
        current->nextSibling = child;
    }
}

int findDepth(TreeNode* root, char target, int currentDepth = 0) {
    if (!root) return -1;
    if (root->data == target) return currentDepth;

    int childDepth = findDepth(root->leftChild, target, currentDepth + 1);
    if (childDepth != -1) return childDepth;

    return findDepth(root->nextSibling, target, currentDepth);
}

int findHeight(TreeNode* node) {
    if (!node) return -1;

    int maxHeight = 0;

    TreeNode* child = node->leftChild;
    
    while (child) {
        maxHeight = max(maxHeight, 1 + findHeight(child));
        child = child->nextSibling;
    }
    
    return maxHeight;
}

TreeNode* findNode(TreeNode* root, char target) {
    if (!root) return nullptr;
    if (root->data == target) return root;

    TreeNode* found = findNode(root->leftChild, target);
    if (found) return found;

    return findNode(root->nextSibling, target);
}

int main() {

    TreeNode* A = new TreeNode('A');
    TreeNode* B = new TreeNode('B');
    TreeNode* C = new TreeNode('C');
    TreeNode* D = new TreeNode('D');
    TreeNode* E = new TreeNode('E');
    TreeNode* F = new TreeNode('F');
    TreeNode* G = new TreeNode('G');
    TreeNode* H = new TreeNode('H');
    TreeNode* I = new TreeNode('I');
    TreeNode* J = new TreeNode('J');
    TreeNode* K = new TreeNode('K');
    TreeNode* L = new TreeNode('L');
    TreeNode* M = new TreeNode('M');
    TreeNode* N = new TreeNode('N');
    TreeNode* P = new TreeNode('P');
    TreeNode* Q = new TreeNode('Q');

    addChild(A, B); addChild(A, C); addChild(A, D); addChild(A, E); addChild(A, F); addChild(A, G);
    addChild(D, H);
    addChild(E, I); addChild(E, J);
    addChild(F, K); addChild(F, L); addChild(F, M);
    addChild(G, N);
    addChild(J, P); addChild(J, Q);

    vector<char> nodes = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'P', 'Q'};
    
    cout << "Node\tHeight\tDepth" << endl;
    cout << "                     " << endl;
    
    for (char c : nodes) {
        TreeNode* targetNode = findNode(A, c);
        int h = findHeight(targetNode);
        int d = findDepth(A, c);
        cout << c << "\t" << h << "\t" << d << endl;
    }

    return 0;
}

