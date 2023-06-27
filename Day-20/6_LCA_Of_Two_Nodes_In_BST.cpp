#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
	if(!root)
        return NULL;
    
    int minVal = min(p->data, q->data);
    int maxVal = max(p->data, q->data);

    while(root)
    {
        if(root->data > maxVal)
            root = root->left;
        else if(root->data < minVal)
            root = root->right;
        else
            return root;
    }

    return NULL;
}