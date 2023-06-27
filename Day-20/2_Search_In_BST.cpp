#include <bits/stdc++.h> 
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

bool searchInBST(BinaryTreeNode<int> *root, int req)
{
    if(!root)
        return false;

    if(root->data == req)
        return true;
    else if(root->data > req)
        return searchInBST(root->left, req);
    else
        return searchInBST(root->right, req);
}