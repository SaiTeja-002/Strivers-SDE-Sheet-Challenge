#include <bits/stdc++.h>

void helper(vector<vector<int>> &maze, int i, int j, vector<int> &vec, vector<vector<int>> &ans)
{
  int n = maze.size();
  if(i < 0 || j < 0 || i >= n || j >= n)
    return ;

  if(i==n-1 && j==n-1)
  {
    vec[n*n-1] = 1;
    ans.push_back(vec);
    return ;
  }

  if(maze[i][j] == 0 || maze[i][j] == 2)
    return ;

  maze[i][j] = 2;
  vec[(n*i)+j] = 1;

  helper(maze, i+1, j, vec, ans); 
  helper(maze, i-1, j, vec, ans); 
  helper(maze, i, j-1, vec, ans); 
  helper(maze, i, j+1, vec, ans); 

  vec[(n*i)+j] = 0;
  maze[i][j] = 1;
}

vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n)
{
  vector<vector<int> > ans;
  vector<int> vec(n*n, 0);
  helper(maze, 0, 0, vec, ans);
  return ans;
}