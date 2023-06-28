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
void traverse(TreeNode<int>* node, int& ans, int& k)
{
    if(!node || !k)
        return ;
    
    traverse(node->right, ans, k);

    if(--k == 0)
    {
        ans = node->data;
        return ;
    }

    traverse(node->left, ans, k);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int ans = -1;
    traverse(root, ans, k);

    return ans;
}
