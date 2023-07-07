#include <bits/stdc++.h>

string fourSum(vector<int> nums, int target, int n)
{
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int left = j + 1, right = n - 1;
            int remain = target - nums[i] - nums[j];
            while (left < right)
            {
                int sum = nums[left] + nums[right];

                if(sum == remain)
                    return "Yes";
                else if(sum > remain)
                    right--;
                else
                    left++;
            }
            while(j+1 < n && nums[j] == nums[j+1]) 
                j++;
        }
        while(i+1 < n && nums[i] == nums[i+1]) 
            i++;
    }

    return "No";
}
