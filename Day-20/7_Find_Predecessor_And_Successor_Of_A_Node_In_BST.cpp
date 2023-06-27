#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
void find(BinaryTreeNode<int>* node, int key, int& pred, int& suc)
{
    if(!node)
        return;

    if(node->data == key)
    {
        // If the node has a left subtree, traverse until the end of its right half
        if(node->left)
        {
            BinaryTreeNode<int>* temp = node->left;

            while(temp->right)
                temp = temp->right;

            pred = temp->data;
        }

        //If the node has a right subtree, traverse until the end of its left half
        if(node->right)
        {
            BinaryTreeNode<int>* temp = node->right;

            while(temp->left)
                temp = temp->left;

            suc = temp->data;
        }

        return ;
    }

    if (node->data < key)
    {
        pred = node->data;
        find(node->right, key, pred, suc);
    }
    else if (node->data > key)
    {
        suc = node->data;
        find(node->left, key, pred, suc);
    }
}

pair<int, int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int pred=-1, suc=-1;
    find(root, key, pred, suc);

    return {pred, suc};
}
