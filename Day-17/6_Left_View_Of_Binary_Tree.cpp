#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

void traverse(TreeNode<int>* node, vector<int>& vec, int curLevel, int& maxLevel)
{
    if(!node)
        return ;
    if(curLevel > maxLevel)
    {
        vec.push_back(node->data);
        maxLevel = curLevel;
    }

    traverse(node->left, vec, curLevel+1, maxLevel);
    traverse(node->right, vec, curLevel+1, maxLevel);
}


vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> vec;
    int maxLevel=0;
    traverse(root, vec, 1, maxLevel);

    return vec;
}