#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>


struct BSTNode {
    int data;            
    BSTNode* left;      
    BSTNode* right;      

    BSTNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

BSTNode* insertNode(BSTNode* node, int val);
void preorderTraversal(BSTNode* node);
void inorderTraversal(BSTNode* node);
void postorderTraversal(BSTNode* node);
void findData(BSTNode* root, std::string choice, int key);

#endif 

