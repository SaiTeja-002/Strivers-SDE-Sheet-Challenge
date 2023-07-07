#include<bits/stdc++.h>

struct TrieNode
{
    TrieNode* child[2];
    
    TrieNode() 
	{
        child[0] = nullptr;
        child[1] = nullptr;
    }
};


class Trie 
{
private:
    TrieNode* root;
    
public:
    Trie() 
	{
        root = new TrieNode();
    }
    
    void insert(int num) 
	{
        TrieNode* cur = root;
        
        for (int i=31; i>=0; i--) 
		{
            int index = ((num >> i) & 1);
            
            if (!cur->child[index])
                cur->child[index] = new TrieNode();
            
            cur = cur->child[index];
        }
    }
    
    int getMax(int x) 
	{
        TrieNode* cur = root;
        int ans = 0;
        
        for (int i=31; i>=0; i--) 
		{
            int index = ((x >> i) & 1);
            
            if (cur->child[1 - index]) 
			{
                ans |= (1 << i);
                cur = cur->child[1 - index];
            } 
			else
                cur = cur->child[index];
        }
        
        return ans;
    }
};

vector<int> maxXorQueries(vector<int>& nums, vector<vector<int>>& queries) 
{
    sort(nums.begin(), nums.end());
    vector<pair<int, pair<int, int>>> offlineQueries;
    
    int q = queries.size();
    
    for(int i=0; i<q; i++)
        offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
    
    sort(offlineQueries.begin(), offlineQueries.end());
    
    vector<int> ans(q, 0);
    int n = nums.size(), ind = 0;
    Trie trie;
    
    for(int i=0; i<q; i++) 
	{
        int till = offlineQueries[i].first;
        int x = offlineQueries[i].second.first;
        int index = offlineQueries[i].second.second;
        
        while (ind < n && nums[ind] <= till) 
		{
            trie.insert(nums[ind]);
            ind++;
        }
        
        if (ind == 0)
            ans[index] = -1; 
		else
            ans[index] = trie.getMax(x);
    }
    
    return ans;
}
