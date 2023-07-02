void dfs(int **nums, vector<vector<int>>&visited, int row, int col, int n, int m){
   if(row<0 || row>=n || col <0 || col>=m || visited[row][col] || nums[row][col]==0)
      return;

   visited[row][col] = 1;

   dfs(nums, visited, row-1, col-1, n, m);
   dfs(nums, visited, row-1, col, n, m);
   dfs(nums, visited, row-1, col+1, n, m);
   dfs(nums, visited, row, col-1, n, m);
   dfs(nums, visited, row, col+1, n, m);
   dfs(nums, visited, row+1, col-1, n, m);
   dfs(nums, visited, row+1, col, n, m);
   dfs(nums, visited, row+1, col+1, n, m);
}

int getTotalIslands(int** nums, int n, int m)
{
   vector<vector<int>> visited(n,vector<int>(m,0));
   int count=0;

   for(int i=0; i<n; i++)
   {
      for(int j=0; j<m; j++)
      {
         if(nums[i][j]==1 && !visited[i][j])
         {
            count++;
            dfs(nums, visited, i, j, n, m);
         }
      }
   }
   
   return count;
}