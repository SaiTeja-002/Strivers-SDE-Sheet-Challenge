bool canColor(vector<vector<int>> &mat, vector<int> &paint, int n, int color, int m, int node)
{
    for (int i=0; i<n; i++)
        if(i != node && mat[node][i] == 1 && paint[i] == color)
            return false; 
    
    return true;   
} 

bool recur(vector<vector<int>> &mat, vector<int>& paint, int n, int m, int start)
{
    if(start == n)
    return true;
    
    for( int i=1; i<=m ; i++)
    {
        if(canColor(mat, paint, n, i, m, start))
        {
            paint[start]=i;

            if(recur(mat, paint, n, m, start+1))
                return true;
            
            paint[start]=0;
        }
    }
    
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) 
{
    int n = mat.size();
    int start=0;
    vector<int>paint(n,0);
    if(recur(mat,paint , n,m , start))return "YES";
    
    return "NO";
}