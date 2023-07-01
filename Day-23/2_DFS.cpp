#include<bits/stdc++.h>

void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& vec)
{
    if(!visited[node])
    {
        visited[node] = 1;
        vec.push_back(node);

        for(auto neighbor:adj[node])
            dfs(neighbor, adj, visited, vec);
    }
}

vector<vector<int>> depthFirstSearch(int numVertices, int numEdges, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(numVertices);
    vector<int> visited(numVertices, 0);
    vector<vector<int>> path;

    // Create the adjacency list
    for(int i=0; i<edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    // Sort the adjacecny list
    for(int i=0; i<adj.size(); i++)
        sort(adj[i].begin(), adj[i].end());

    // Traverse through the connected and unconnected components
    for(int i=0; i<adj.size(); i++)
    {
        if(!visited[i])
        {
            vector<int> vec;
            dfs(i, adj, visited, vec);
            path.push_back(vec);
        }
    }

    return path;
}