#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void traverse(BinaryTreeNode<int>* node, int level, map<int, vector<int>>& mp)
{
    if(!node)
        return ;
    
    mp[level].push_back(node->val);

    traverse(node->left, level+1, mp);
    traverse(node->right, level+1, mp);
}

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> vec;
    map<int, vector<int>> mp;
    traverse(root, 0, mp);

    for(auto key:mp)
    {
        for(auto e:key.second)
            vec.push_back(e);
    }

    return vec;
}