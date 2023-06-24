void addBoard(vector<vector<int>> &board, vector<vector<int>> &res)
{
    vector<int> temp;
    int n = board.size();
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            temp.push_back(board[i][j]);

    res.push_back(temp);
}

bool isPossible(vector<vector<int>>& res,int n,int i,int j)
{
    for(int col=0; col<n; col++)
        if(res[i][col] == 1)
            return false;
    
    for(int row=0; row<n; row++)
        if(res[row][j] == 1) 
            return false;
    
    for(int row=i, col=j; row>=0 && col>=0; row--, col--)
        if(res[row][col]==1) 
            return false;
    
    for(int row=i, col=j; row>=0 && col<n; row--, col++)
        if(res[row][col]==1)
            return false;
    
    return true;
}

void solve(vector<vector<int>>& res, int n, int i, int j, vector<vector<int>>& ans)
{
    if(i == n)
    {
        addBoard(res, ans);
        return;
    }
    
    for(int col=j; col<n; col++)
    {
        if(isPossible(res, n, i, col))
        {
            res[i][col] = 1;
            solve(res, n, i+1, 0, ans);
            res[i][col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> res(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(res, n, 0, 0, ans);
    return ans;
}