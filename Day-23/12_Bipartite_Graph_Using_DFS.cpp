#include<bits/stdc++.h>

bool dfs(int node, vector<vector<int>>& adj, vector<int>& color, int paint)
{
	if (color[node])
		return color[node] == paint;

	color[node] = paint;
	
	for (int neighbor : adj[node])
		if (!dfs(neighbor, adj, color, -paint))
			return false;

	return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges)
{
	vector<vector<int>> adj(edges.size());

	for(int i=0; i<edges.size(); i++)
	{
		for(int j=0; j<edges.size(); j++)
		{
			if(edges[i][j])
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	int n = adj.size();
	vector<int> color(n, 0);

	for (int i=0; i<n; i++)
		if (color[i] == 0 && !dfs(i, adj, color, 1))
			return false;

	return true;
}

