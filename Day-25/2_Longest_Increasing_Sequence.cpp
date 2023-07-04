#include<bits/stdc++.h>  

int longestIncreasingSubsequence(int arr[], int n)
{
    if(n==0)
      return 0;

    vector<int> ans;
    ans.push_back(arr[0]);

    for(int i=1; i<n; i++)
    {
        if(arr[i] > ans.back())
            ans.push_back(arr[i]);
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[index] = arr[i];
        }
    }

    return ans.size();
}

// The following code worked in LeetCode

// int longestIncreasingSubsequence(int nums[], int n)
// {
//     vector<int> dp(n, 1);

//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<i; j++)
//         {
//             if(nums[i] > nums[j])
//                 dp[i] = max(dp[i], dp[j]+1);
//         }
//     }

//     return *max_element(dp.begin(), dp.end());
// }
