#ifndef GENERAL_TREE_H
#define GENERAL_TREE_H

#include <algorithm>

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

void addChild(TreeNode* parent, TreeNode* child);
int findDepth(TreeNode* root, char target, int currentDepth = 0);
int findHeight(TreeNode* node);
TreeNode* findNode(TreeNode* root, char target);

#endif 

