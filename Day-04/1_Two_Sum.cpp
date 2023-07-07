#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &nums, int target)
{
   for(int i=0; i<nums.size(); i++)
      for(int j=i+1; j<nums.size(); j++)
         if(nums[i]+nums[j] == target)
            pairs.push_back({min(nums[i], nums[j]), max(nums[i], nums[j])});

   sort(pairs.begin(), pairs.end());
   return pairs;   
}