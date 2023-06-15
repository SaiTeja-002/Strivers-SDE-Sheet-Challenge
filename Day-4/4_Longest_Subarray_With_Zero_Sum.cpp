#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector<int> nums)
{
    unordered_map<int, int> map;
    int sum = 0, longest = 0;
    
    for(int i=0; i<nums.size(); i++)
    {
        sum += nums[i];
        
        if(sum == 0)
            longest = max(longest, i+1);
        else if(map.find(sum) != map.end())
            longest = max(longest, i-map[sum]);
        else
            map[sum] = i;
    }
    
    return longest;
}