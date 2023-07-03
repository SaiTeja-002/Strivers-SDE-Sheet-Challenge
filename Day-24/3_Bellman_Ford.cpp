int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<int> dist(n+1, 1e9);
    dist[src] = 0;

    int itr = n-1;

    while(itr--)
    {
        for(int i=0; i<edges.size(); i++)
        {
            int u=edges[i][0], v=edges[i][1], wt=edges[i][2];

            if(dist[u] != 1e9 && dist[u]+wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }

    return dist[dest];
}