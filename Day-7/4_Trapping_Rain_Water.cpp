#include <bits/stdc++.h> 

long getTrappedWater(long *nums, int n)
{
    long left[n] = {0}, right[n] = {0}, fill[n] = {0};

    left[0] = nums[0];
    right[n-1] = nums[n-1];

    for (long i=1; i<n; i++)
        left[i] = max(left[i-1], nums[i]);

    for (long i=n-2; i>=0; i--)
        right[i] = max(right[i+1], nums[i]);

    for(long i=0; i<n; i++)
        fill[i] = min(left[i], right[i]) - nums[i];
    
    long ans=0;

    for(long i=0; i<n; i++)
        ans += fill[i]; 

    return ans;
}