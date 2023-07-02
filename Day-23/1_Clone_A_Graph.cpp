#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

void dfs(graphNode* node, unordered_map<graphNode*, graphNode*>& mp)
{
    graphNode* copy = new graphNode(node->data);
    mp[node] = copy;

    for(auto neighbor : node->neighbours)
    {
        if(mp.find(neighbor) != mp.end())
            copy->neighbours.push_back(mp[neighbor]);
        else
        {
            dfs(neighbor, mp);
            copy->neighbours.push_back(mp[neighbor]);
        }
    }
}

graphNode *cloneGraph(graphNode *node)
{
    if(!node)
		return NULL;

	unordered_map<graphNode*, graphNode*> mp;
    dfs(node, mp);

    return mp[node];
}