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

void traverse(BinaryTreeNode<int>* node, map<int, vector<int>>& mp, int level)
{
    if(!node)
        return ;
    
    mp[level].push_back(node->data);

    traverse(node->left, mp, level+1);
    traverse(node->right, mp, level+1);
}

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    map<int, vector<int>> mp;
    vector<int> vec;

    traverse(root, mp, 0);

    for(auto& row:mp)
    {
        if(row.first%2)
        {
            reverse(row.second.begin(), row.second.end());
            for(auto e:row.second)
                vec.push_back(e);
        }
        else
        {
            for(auto e:row.second)
                vec.push_back(e);
        }
    }

    return vec;
}
