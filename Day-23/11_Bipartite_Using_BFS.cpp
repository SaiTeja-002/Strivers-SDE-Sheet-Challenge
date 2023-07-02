bool isGraphBirpatite(vector<vector<int>> &edges)
{
	int numVertices = edges.size();
	vector<vector<int>> adj(numVertices);

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

	vector<int> color(numVertices, 0);
	queue<int> q;

	for(int i=0; i<numVertices; i++)
	{
		if(!color[i])
		{
			color[i] = 1;
			q.push(i);
			
			while(!q.empty())
			{
				int node = q.front();
				q.pop();

				for(int neighbor:adj[node])
				{
					if(!color[neighbor]) 
					{
						color[neighbor] = -color[node];
						q.push(neighbor);
					} 
					else if(color[neighbor] == color[node])
						return false;
				}
			}
		}
	}

	return true;
}