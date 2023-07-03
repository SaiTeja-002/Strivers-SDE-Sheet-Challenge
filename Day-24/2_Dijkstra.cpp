#include <bits/stdc++.h>

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    vector<int> dis(vertices, INT_MAX);
    vector<pair<int, int>> adj[vertices];

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    dis[0] = 0;

    for(auto e:vec)
    {
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }

    while(!pq.empty())
    {
        pair<int, int> node = pq.top();
        pq.pop();

        vector<pair<int, int>> nodes = adj[node.second];

        for(auto e:nodes)
        {
            int ndis = node.first + e.second;

            if(ndis < dis[e.first])
            {
                dis[e.first] = ndis;
                pq.push({ndis, e.first});
            }
        }
        
    }
    
    return dis;
}