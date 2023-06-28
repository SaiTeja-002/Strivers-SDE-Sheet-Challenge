#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

void traverse(BinaryTreeNode<int>* node, int req, int& ceil, int& temp)
{
    if(!node)
        return ;
    
    if(node->data == req)
    {
        ceil = req;
        return ;
    }

    if(node->data > req)
    {
        if(node->data < temp)
        {
            temp = node->data;
            ceil = node->data;
        }
        traverse(node->left, req, ceil, temp);
    }
    else
        traverse(node->right, req, ceil, temp);
}

int findCeil(BinaryTreeNode<int> *root, int req)
{
    int ceil = -1, temp = INT_MAX;
    traverse(root, req, ceil, temp);

    return ceil;
}