#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void traverse(vector<int>& vec, TreeNode* node)
{
    if(!node)
        return ;
    
    traverse(vec, node->left);
    vec.push_back(node->data);
    traverse(vec, node->right);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> vec;
    traverse(vec, root);

    return vec;
}