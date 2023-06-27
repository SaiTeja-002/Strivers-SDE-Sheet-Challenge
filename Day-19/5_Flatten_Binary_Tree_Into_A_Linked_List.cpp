#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void traverse(TreeNode<int>* node, vector<TreeNode<int>*>& vec)
{
    if(!node)
        return ;
    
    vec.push_back(node);
    traverse(node->left, vec);
    traverse(node->right, vec);
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    if(!root)
        return root;

    vector<TreeNode<int>*> vec;
    traverse(root, vec);

    for(int i=0; i<vec.size()-1; i++)
    {
        vec[i]->left = NULL;
        vec[i]->right = vec[i+1];
    }

    return root;
}