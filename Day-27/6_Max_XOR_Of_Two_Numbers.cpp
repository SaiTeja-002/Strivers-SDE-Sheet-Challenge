#include <bits/stdc++.h>

struct TrieNode
{
    TrieNode* child[2];
    TrieNode() 
    {
        child[0] = NULL;
        child[1] = NULL;
    }
};

void insert(TrieNode* root, int num)
{
    TrieNode* cur = root;

    for(int i=31; i>=0; i--)
    {
        int ind = (num>>i)&1;

        if(!cur->child[ind])
            cur->child[ind] = new TrieNode();
        
        cur = cur->child[ind];
    }
}

int findMax(TrieNode* root, int num)
{
    TrieNode* cur = root;
    int ret = 0;

    for(int i=31; i>=0; i--)
    {
        int ind = (num>>i)&1;

        if(cur->child[1-ind] != NULL)
        {
            cur = cur->child[1-ind];
            ret = ret | ((1<<i));
        }
        else
            cur = cur->child[ind];
    }

    return ret;
}

int maximumXor(vector<int> arr)
{
    TrieNode* root = new TrieNode();

    for(auto& it:arr)
        insert(root, it);
    
    int ans = 0;
    for(auto& it:arr)
        ans = max(ans, findMax(root, it));
    
    return ans;
}
