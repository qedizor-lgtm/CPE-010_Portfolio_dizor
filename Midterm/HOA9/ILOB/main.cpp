#include <iostream>
#include <string>
#include <vector>
#include "BST.h"

using namespace std;

BSTNode* insertNode(BSTNode* node, int val) {
    if (!node) {
        return new BSTNode(val);
    }
    if (val < node->data) {
        node->left = insertNode(node->left, val);
    } else if (val > node->data) {
        node->right = insertNode(node->right, val);
    }
    return node;
}

void preorderTraversal(BSTNode* node) {
    if (!node) return;
    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void inorderTraversal(BSTNode* node) {
    if (!node) return;
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

void postorderTraversal(BSTNode* node) {
    if (!node) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
}

bool searchBST(BSTNode* node, int key) {
    if (!node) return false;
    if (node->data == key) return true;
    if (key < node->data) return searchBST(node->left, key);
    return searchBST(node->right, key);
}

void findData(BSTNode* root, string choice, int key) {

    for (auto &c : choice) c = toupper(c);
    
    bool found = searchBST(root, key);
    
    if (found) {
        cout << "\"" << key << "\" was found!" << endl;
    }
}

int main() {
    BSTNode* root = nullptr;

    vector<int> initialValues = {50, 30, 20, 40, 70, 60, 80};
    for (int val : initialValues) {
        root = insertNode(root, val);
    }

    cout << "Pre-order:  "; preorderTraversal(root);  cout << endl;
    cout << "In-order:   "; inorderTraversal(root);   cout << endl; 
    cout << "Post-order: "; postorderTraversal(root); cout << endl << endl;

    findData(root, "INORDER", 40);
    cout << endl;

    root = insertNode(root, 45);

    findData(root, "PREORDER", 45);

    return 0;
}

