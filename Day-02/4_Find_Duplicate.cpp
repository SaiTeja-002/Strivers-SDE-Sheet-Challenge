#include <bits/stdc++.h>

int findDuplicate(vector<int> &nums, int n)
{
	// Sort the vector
	sort(nums.begin(), nums.end());

	// Find the duplicate
	for(int i=0; i<n-1; i++)
	{
		if(nums[i] == nums[i+1])
			return nums[i];
	}

	return nums[0];
}
