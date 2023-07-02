bool detectCycleInDirectedGraph(int numVertices, vector<pair<int, int>>& edges)
{
    vector<vector<int>> adj(numVertices+1);
    vector<int> indegree(numVertices+1, 0);
    queue<int> q;

    for(auto edge:edges)
    {
        int u=edge.first, v=edge.second;

        adj[u].push_back(v);
        indegree[v]++;
    }

    for(int i=1; i<=numVertices; i++)
        if(!indegree[i])
            q.push(i);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto neighbor:adj[node])
        {
            indegree[neighbor]--;

            if (!indegree[neighbor])
                q.push(neighbor);
        }
    }

    for(int i=1; i<=numVertices; i++)
        if (indegree[i]>0)
            return true;

    return false;
}