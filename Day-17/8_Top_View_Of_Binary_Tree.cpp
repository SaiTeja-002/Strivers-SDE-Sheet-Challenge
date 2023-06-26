#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void traverse(TreeNode<int>* node, map<int, pair<int, int>>& mp, int level, int distance)
{
    if(!node)
        return ;

    if(mp.find(distance) == mp.end() || level < mp[distance].second)
        mp[distance] = {node->val, level};

    traverse(node->left, mp, level + 1, distance - 1);
    traverse(node->right, mp, level + 1, distance + 1);
}

vector<int> getTopView(TreeNode<int>* root)
{
    vector<int> topView;

    map<int, pair<int, int>> mp;
    traverse(root, mp, 0, 0);

    for(auto& entry : mp)
        topView.push_back(entry.second.first);

    return topView;
}


/*
void traverse(TreeNode<int>* node, map<int, vector<int>>& mp, int level)
{
    if(!node)
        return ;
    
    mp[level].push_back(node->val);

    traverse(node->left, mp, level-1);
    traverse(node->right, mp, level+1);
}

vector<int> getTopView(TreeNode<int> *root)
{
    // int left=0, right=0;
    vector<int> vec;
    if(!root)
        return {};
    map<int, vector<int>> mp;
    traverse(root, mp, 0);

    for(auto row:mp)
    {
        vec.push_back(row.second[0]);
    }
    // traverse(root, vec, left, right, 0);

    return vec;   
} */ 
