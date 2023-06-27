#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNext(BinaryTreeNode<int>* node, map<int, vector<BinaryTreeNode<int>*>>& mp, int level)
{
    if(!node)
        return ;
    
    mp[level].push_back(node);
    connectNext(node->left, mp, level+1);
    connectNext(node->right, mp, level+1);
}

void connectNodes(BinaryTreeNode<int> *root)
{
    map<int, vector<BinaryTreeNode<int>*>> mp;
    connectNext(root, mp, 0);

    for(auto& entry:mp)
    {
        for(int i=0; i<entry.second.size()-1; i++)
            entry.second[i]->next = entry.second[i+1];
        
        entry.second[entry.second.size()-1] = NULL;
    }
}