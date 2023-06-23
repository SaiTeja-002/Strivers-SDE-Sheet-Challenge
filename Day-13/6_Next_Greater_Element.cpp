// Similar to temperatures

#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &nums, int n)
{
    stack<int> indices;
    vector<int> ng(n, -1);

    for(int i=0; i<n; i++)
    {
        while(!indices.empty() && nums[i] > nums[indices.top()])
        {
            ng[indices.top()] = nums[i];
            indices.pop();
        }

        indices.push(i);
    }

    return ng;
}
