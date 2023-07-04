#include <bits/stdc++.h> 
int maximumProduct(vector<int> &nums, int n)
{
	int maxProd=1, minProd=1, ans=INT_MIN;

	for(int& num:nums)
	{
		if(num < 0)
			swap(maxProd, minProd);

		maxProd = max(maxProd*num, num);
		minProd = min(minProd*num, num);

		ans = max(maxProd, ans);
	}

	return ans;
}
