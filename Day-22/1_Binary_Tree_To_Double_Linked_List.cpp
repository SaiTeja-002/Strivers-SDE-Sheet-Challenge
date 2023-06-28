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

void traverse(BinaryTreeNode<int>* root, vector<int>& vec)
{
    if(!root)
        return ;

    traverse(root->left, vec);
    vec.push_back(root->data);
    traverse(root->right, vec);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root)
{
    vector<int> vec;
    traverse(root, vec);

    BinaryTreeNode<int> *head = new BinaryTreeNode<int>(-1), *cur=head, *prev=NULL;
    
    for(auto& e:vec)
    {
        BinaryTreeNode<int>* t = new BinaryTreeNode<int>(e);
        cur->right = t;
        cur->left = prev;
        prev = cur;
        cur = cur->right;
    }
    cur->right = NULL;

    return head->right;
}