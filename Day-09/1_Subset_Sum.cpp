#include <bits/stdc++.h>

void fun(vector<int> arr, int index, vector<int>& sums, int sum)
{
    if(index == arr.size())
    {
        sums.push_back(sum);
        return ;
    }
    
    fun(arr, index+1, sums, sum);
    fun(arr, index+1, sums, sum+arr[index]);
}

vector<int> subsetSum(vector<int> &nums)
{
    vector<int> sums;
    int sum=0, index=0;
    
    fun(nums, index, sums, sum);

    sort(sums.begin(), sums.end());
    
    return sums;
}