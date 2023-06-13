#include <bits/stdc++.h>

long long maxSubarraySum(int arr[], int n)
{
    long long int curSum = arr[0], maxSum = arr[0];

    for(int i=1; i<n; i++)
    {
        curSum = max((long long int) 0, curSum+(long long int) arr[i]);
        maxSum = max(curSum, maxSum);
    }

    return maxSum;
}