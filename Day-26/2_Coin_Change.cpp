#include<bits/stdc++.h>

long fun(int ind, int value, int *denomination, vector<vector<long>> &dp)
{
    if(ind == 0)
        return (value%denomination[0] == 0);

    if(dp[ind][value] != -1)
        return dp[ind][value];

    long notTake = fun(ind-1, value, denomination, dp);
    long take = 0;

    if(denomination[ind] <= value)
        take = fun(ind, value-denomination[ind], denomination, dp);

    return dp[ind][value] = take+notTake;
}


long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value+1, -1));

    return fun(n-1, value, denominations, dp);
}