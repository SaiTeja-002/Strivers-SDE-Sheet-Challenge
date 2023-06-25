#include<bits/stdc++.h>

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;

    if(!root)
        return ans;
    
    map<int, vector<int>> nodes;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});

    while(!q.empty())
    {
        root = q.front().first;
        int y = q.front().second;
        q.pop();

        nodes[y].emplace_back(root->data);

        if(root->left)
            q.push({root->left, y-1});
        if(root->right)
            q.push({root->right, y+1});
    }

    for(auto &it:nodes)
        ans.insert(ans.end(), it.second.begin(), it.second.end());
    
    return ans;
}
