#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

void traverse(BinaryTreeNode<int>* node, map<int, pair<int, int>>& mp, int level, int distance)
{
    if(!node)
        return ;
    
    if(mp.find(level) != mp.end())
    {
        if(distance >= mp[level].second)
            mp[level] = {node->data, distance};
    }
    else
        mp[level] = {node->data, distance};

    traverse(node->left, mp, level-1, distance+1);
    traverse(node->right, mp, level+1, distance+1);
}

vector<int> bottomView(BinaryTreeNode<int>* root)
{
    vector<int> vec;
    map<int, pair<int, int>> mp;
    traverse(root, mp, 0, 0);

    for(auto entry:mp)
        vec.push_back(entry.second.first);

    return vec;
}
