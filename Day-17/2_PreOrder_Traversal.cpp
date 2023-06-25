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

void traverse(TreeNode* node, vector<int>& vec)
{
    if(!node)
        return ;
    
    vec.push_back(node->data);
    traverse(node->left, vec);
    traverse(node->right, vec);
}


vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> vec;
    traverse(root, vec);

    return vec;
}