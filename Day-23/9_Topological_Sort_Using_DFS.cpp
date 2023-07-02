#include <bits/stdc++.h> 

void dfs(vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st, int node)
{    
    if(visited[node]) 
        return;
    visited[node] = true;

    for(int v:adj[node])
    {
        if(!visited[v])
            dfs(adj, visited, st, v);
    }

    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) 
{
    vector<vector<int>> adj(v);

    for(auto edge:edges)
        adj[edge[0]].push_back(edge[1]);

    vector<bool> visited(v, false);
    stack<int> st;

    for(int i=0; i<v; i++)
    {
        if(!visited[i])
            dfs(adj, visited, st, i);      
    }
    
    vector<int> ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}