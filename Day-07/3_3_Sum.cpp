#include <bits/stdc++.h> 

vector<vector<int>> findTriplets(vector<int>nums, int n, int target)
{
	// Three Pointers
	sort(nums.begin(), nums.end());     // O(NlogN)
	
	vector<vector<int>> ans;

	for(int i=0; i<nums.size()-2; i++)
	{
		if(i>0 && nums[i] == nums[i-1])
			continue;

		int j = i+1;
		int k = nums.size()-1;

		while(j < k)
		{
			int sum = nums[i]+nums[j]+nums[k];

			if(sum == target)
			{
				ans.push_back({nums[i], nums[j], nums[k]});
				j++;
				k--;
				
				while(nums[j] == nums[j-1] && j<k)
					j++;

				while(nums[k] == nums[k+1] && k>j)
					k--;
			}
			else if(sum < target)
				j++;
			else
				k--;
		}
		
	}

	return ans;
}