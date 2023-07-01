#include<bits/stdc++.h>
vector<int> BFS(int numVertices, vector<pair<int, int>> edges)
{
    vector<vector<int>> adjacencyList(numVertices);
    vector<int> visited(numVertices, 0);
    vector<int> path;
    queue<int> q;
    
    for(int i=0; i<edges.size(); i++)
    {
        adjacencyList[edges[i].first].push_back(edges[i].second);
        adjacencyList[edges[i].second].push_back(edges[i].first);
    }
    
    for(int i=0; i<numVertices; i++)
        sort(adjacencyList[i].begin(), adjacencyList[i].end());

    for(int i=0; i<numVertices; i++)
    {
        if(!visited[i])
        {
            q.push(i);
            visited[i] = 1;
            
            while(!q.empty())
            {
                int node = q.front();
                q.pop();

                path.push_back(node);
                
                for(auto& neighbor:adjacencyList[node])
                {
                    if(!visited[neighbor])
                    {
                        visited[neighbor] = 1;
                        q.push(neighbor);
                    }
                }
            }
        }
    }
    
    return path;
}
