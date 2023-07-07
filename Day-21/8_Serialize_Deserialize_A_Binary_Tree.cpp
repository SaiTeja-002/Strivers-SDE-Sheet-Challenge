#include<bits/stdc++.h>

string serializeTree(TreeNode<int>* root)
{
    if(!root)
        return "";
    
    string serialized;
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()) 
    {
        TreeNode<int>* cur = q.front();
        q.pop();
        
        if(!cur) 
        {
            serialized += "*,";
            continue;
        }
        
        serialized += to_string(cur->data);
        serialized += ",";
        
        q.push(cur->left);
        q.push(cur->right);
    }
    
    return serialized;
}

TreeNode<int>* deserializeTree(string& serialized)
{
    if(serialized.empty())
        return NULL;
    
    stringstream ss(serialized);
    string str;
    getline(ss, str, ',');
    
    TreeNode<int>* root = new TreeNode<int>(stoi(str));
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()) 
    {
        TreeNode<int>* cur = q.front();
        q.pop();
        
        getline(ss, str, ',');
        
        if (str == "*")
            cur->left = NULL;
        else 
        {
            TreeNode<int>* leftNode = new TreeNode<int>(stoi(str));
            cur->left = leftNode;
            q.push(leftNode);
        }
        
        getline(ss, str, ',');
        
        if(str == "*")
            cur->right = nullptr;
        else
        {
            TreeNode<int>* rightNode = new TreeNode<int>(stoi(str));
            cur->right = rightNode;
            q.push(rightNode);
        }
    }
    
    return root;
}
