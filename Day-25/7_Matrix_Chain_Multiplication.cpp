#include <bits/stdc++.h> 

int matrixMultiplication(vector<int> &nums, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    for(int i=0; i<n-1; i++)
        dp[i][i+1] = 0;
    for(int gap=2; gap<n; gap++)
    {
        for(int i=0; i+gap<n; i++)
        {
            int j = i+gap;

            for(int k=i+1; k<j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + nums[i]*nums[k]*nums[j]);
        }
    }
    
    return dp[0][n-1];
}