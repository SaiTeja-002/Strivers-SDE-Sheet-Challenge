#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
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

*************************************************************/
void validate(BinaryTreeNode<int>* node, bool& valid, BinaryTreeNode<int>*& prev)
{
    if(!node || !valid)
        return ;

    validate(node->left, valid, prev);

    if(prev && prev->data > node->data)
    {
        valid = false;
        return ;
    }

    prev = node;

    validate(node->right, valid, prev);
}

bool validateBST(BinaryTreeNode<int> *root)
{
    bool valid = true;
    BinaryTreeNode<int>* prev = NULL;

    validate(root, valid, prev);

    return valid;
}