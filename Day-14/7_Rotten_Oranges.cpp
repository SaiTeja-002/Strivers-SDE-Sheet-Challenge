#include<bits/stdc++.h>

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    vector<vector<int>> visted(n, vector<int>(m, 0));
    queue<pair<int, pair<int, int>>> q;

    int countFresh=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] == 1)
                countFresh++;
            else if(grid[i][j] == 2)
            {
                q.push({0, {i, j}});
                visted[i][j]=2;
            }
        }
    }

    int maxtime=0, count=0;

    int r[] = {0, 1, 0, -1};
    int c[] = {-1, 0, 1, 0};

    while(!q.empty())
    {
        auto p = q.front();
        q.pop();

        int time=p.first;
        int i=p.second.first;
        int j=p.second.second;

        maxtime = max(time, maxtime);

        for(int it=0; it<4; it++)
        {
           int nr = r[it]+i;
           int nc = c[it]+j;
           
           if(nr>=0 and nr<n and nc>=0 and nc<m)
           {
               if(!visted[nr][nc] and grid[nr][nc]==1)
               {
                   q.push({time+1, {nr, nc}});
                   visted[nr][nc]=2;
                   count++;
               }
           }
        }
    }

    if(countFresh != count)
        return -1;

    return maxtime;
}