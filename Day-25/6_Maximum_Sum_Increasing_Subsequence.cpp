#include <bits/stdc++.h> 
int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{
	vector<int> dp(n, 1);
	vector<int> ans(arr.begin(), arr.end());

	for(int i=1; i<n; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(arr[j]<arr[i] && dp[j]==dp[i])
			{
				dp[i]++;
				ans[i] = max(ans[i], arr[i]+ans[j]);
			}
		}
	}
	
	return *max_element(ans.begin(),ans.end());
}