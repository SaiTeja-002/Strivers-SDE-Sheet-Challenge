#include<bits/stdc++.h>

bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited)
{
    if(visited[node])
        return true;
    
    if(!visited[node])
    {
        visited[node] = 1;

        for(auto neighbor:adj[node])
            if(neighbor != parent)
                if(dfs(neighbor, node, adj, visited))
                    return true;
    }

    return false;
}


string cycleDetection(vector<vector<int>>& edges, int numVertices, int numEdges)
{
    vector<vector<int>> adj(numVertices+1);
    vector<int> visited(numVertices+1, 0);

    // Construct the adjacency list
    for(auto edge:edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    // Sort the adjacency list
    for(int i=0; i<=numVertices; i++)
        sort(adj[i].begin(), adj[i].end());

    for(int i=1; i<=numVertices; i++)
    {
        if(!visited[i])
        {
            if(dfs(i, -1, adj, visited))
                return "Yes";
        }
    }

    return "No";
}
