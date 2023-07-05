#include<bits/stdc++.h>

int fun(vector<int> &price, int req, vector<int>&dp)
{   
	if(req == 0)
		return 0;

	int take = 0;

	if(dp[req] != -1)
		return dp[req];

	for(int i=1; i<=req; i++)
			take = max(take, price[i-1]+fun(price, req-i, dp));

	return dp[req] = take;
}


int cutRod(vector<int> &price, int n)
{
    vector<int> dp(n+1, -1);
    return fun(price, n, dp);
}