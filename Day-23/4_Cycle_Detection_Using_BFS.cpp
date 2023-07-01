#include<bits/stdc++.h>

bool bfs(int node, vector<vector<int>> adj, vector<int>& visited)
{
    visited[node] = 1;

    queue<pair<int, int>> q;
    q.push({node, -1});

    while(!q.empty())
    {
        int parent = q.front().second;
        int node = q.front().first;
        q.pop();

        for(auto neighbor:adj[node])
        {
            if(!visited[neighbor])
            {
                visited[neighbor] = 1;
                q.push({neighbor, node});
            }
            else if(visited[node] && parent != neighbor)
                return true;
        }
    }

    return false;
}

string cycleDetection(vector<vector<int>>& edges, int numVertices, int numEdges)
{
    vector<vector<int>> adj(numVertices+1);
    vector<int> visited(numVertices+1, 0);

    // Create an adjacency list
    for(int i=0; i<edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    // Sort the list
    for(int i=1; i<numVertices; i++)
        sort(adj[i].begin(), adj[i].end());

    for(int i=0; i<visited.size(); i++)
    {
        if(!visited[i])
        {
            if(bfs(i, adj, visited))
                return "Yes";
        }
    }

    return "No";
}
