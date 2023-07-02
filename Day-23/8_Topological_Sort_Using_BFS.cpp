#include <bits/stdc++.h> 

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) 
{
    vector<int> inDegree(v, 0);
    vector<vector<int>> adj(v);

    for(auto edge:edges)
    {
        adj[edge[0]].push_back(edge[1]);
        inDegree[edge[1]]++;
    }   
    
    vector<bool> visited(v, false);
    queue<int> q;
    
    for(int i=0; i<v; i++)
        if(!inDegree[i]) 
            q.push(i);
    
    vector<int> ans;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        ans.push_back(cur);
        visited[cur] = true;

        for(int u:adj[cur])
        {
            if(!visited[u])
            {
                inDegree[u]--;
                if(!inDegree[u]) 
                    q.push(u);
            }
        }
    }
        
    return ans;
}
