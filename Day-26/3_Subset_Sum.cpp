#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &nums)
{
    bool dp[n+1][k+1];

    for(int i=0; i<n+1; i++)
        dp[i][0] = true;
    for(int i=1; i<k+1; i++)
        dp[0][i] = false;

    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<k+1; j++)
        {
            if(nums[i-1] <= j)
                dp[i][j] = ((dp[i-1][j-nums[i-1]]) || (dp[i-1][j]));
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][k];
}