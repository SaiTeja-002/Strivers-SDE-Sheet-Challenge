#include<bits/stdc++.h>

void fun(vector<int>& nums, int target, vector<vector<int>>& res, int index, vector<int>& vec)
{
    if(index == nums.size())
    {
        if(target == 0 && !vec.empty())
            res.push_back(vec);

        return ;
    }

    fun(nums, target, res, index+1, vec);

    vec.push_back(nums[index]);
    fun(nums, target-nums[index], res, index+1, vec);
    vec.pop_back();
}


vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> res;
    vector<int> vec;
    
    fun(arr, k, res, 0, vec);

    return res;
}