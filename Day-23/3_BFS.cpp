class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[])
    {
        vector<int> ans;
        vector<bool> visited(v+1, false);
        queue<int> q;
        
        visited[0] = true;
        q.push(0);
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            
            ans.push_back(front);
            
            for(auto &i : adj[front])
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        
        return ans;
    }
};