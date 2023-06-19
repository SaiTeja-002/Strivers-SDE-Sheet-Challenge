#include<bits/stdc++.h>

// void fun(vector<int> nums, int target, int sum, int index, vector<vector<int>>& res, vector<int>& vec)
// {
// 	if(target == 0)
// 	{
// 		res.push_back(vec);
// 		return ;
// 	}
// 	if(index == nums.size() || target<0)
// 		return ;

// 	fun(nums, target, 0, index+1, res, vec);
// 	vec.push_back(nums[index]);
// 	fun(nums, target-nums[index], 0, index+1, res, vec);
// 	vec.push_back(nums[index]);
// }


// vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
// {
// 	vector<vector<int>> res;
// 	vector<int> vec;

// 	fun(arr, target, 0, 0, res, vec);

// 	for(auto &row:res)
// 		sort(row.begin(), row.end());

// 	return res;
// }


void fun(vector<int> nums, int target, int index, vector<vector<int>>& res, vector<int>& vec)
{
	if(target == 0)
	{
		sort(vec.begin(), vec.end());
		res.push_back(vec);
		return ;
	}
	if(target < 0)
		return ;
	
	for(int i=index; i<nums.size(); i++)
	{
		if(i != index && nums[i] == nums[i-1])
			continue;

		target -= nums[i];
		vec.push_back(nums[i]);
		fun(nums, target, i+1, res, vec);
		target += nums[i];
		vec.pop_back();
	}
}


vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	sort(arr.begin(), arr.end());

	vector<int> vec;
	vector<vector<int>> res;

	fun(arr, target, 0, res, vec);

	return res;
}