#include<bits/stdc++.h>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adj;

    for(int i=0; i<g.size(); i++)
    {
        int u = g[i].first.first, v = g[i].first.second, w = g[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for(int i=0; i<=n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    key[1] = 0;
    parent[1] = -1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 1));

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if(!mst[u])
        {
            mst[u] = true;

            for(auto it:adj[u])
            {
                int v = it.first, w = it.second;

                if(!mst[v] && w<key[v])
                {
                    parent[v] = u;
                    key[v] = w;
                    pq.push(make_pair(key[v], v));
                }
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;

    for(int i=2; i<=n; i++)
        result.push_back({{parent[i], i}, key[i]});

    return result;
}
