
bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recursionStack)
{
    visited[node] = true;
    recursionStack[node] = true;

    for(auto neighbor:adj[node])
    {
        if(!visited[neighbor])
        {
            if(dfs(neighbor, adj, visited, recursionStack))
                return true;
        }
        else if(recursionStack[neighbor])
        {
            return true;
        }
    }

    recursionStack[node] = false;
    return false;
}

bool detectCycleInDirectedGraph(int numVertices, vector<pair<int, int>>& edges)
{
    vector<vector<int>> adj(numVertices + 1);
    vector<bool> visited(numVertices + 1, false);
    vector<bool> recursionStack(numVertices + 1, false);

    for(auto edge : edges)
        adj[edge.first].push_back(edge.second);

    for(int i=1; i<=numVertices; i++)
    {
        if(!visited[i])
        {
            if(dfs(i, adj, visited, recursionStack))
                return true;
        }
    }

    return false;
}
