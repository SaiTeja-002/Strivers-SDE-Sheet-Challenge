bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int m = matrix.size(), n = matrix[0].size(), start = 0, end = m*n-1;

    while(start <= end)
    {
        int ind = start+((end-start)/2);    // To avoid overflow
        int val = matrix[ind/n][ind%n];

        if(val == target)
            return true;
        else if(val > target)
            end = ind-1;
        else
            start = ind+1;
    }

    return false;        
}