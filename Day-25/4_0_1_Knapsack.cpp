#include <bits/stdc++.h>

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<int> prev(w+1, 0);
	
	for(int i=weights[0]; i<=w; i++)
		prev[i] = values[0];

	for(int i=1; i<n; i++)
	{
		for(int cap=w; cap>=0; cap--)
		{
			int notTaken = prev[cap], taken = INT_MIN;

			if(weights[i] <= cap)
				taken = values[i] + prev[cap-weights[i]];

			prev[cap] = max(notTaken, taken);
		}
	}
	
	return prev[w];
}