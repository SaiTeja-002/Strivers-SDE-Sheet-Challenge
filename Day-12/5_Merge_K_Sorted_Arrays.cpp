#include <bits/stdc++.h> 

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> vec;

    for(auto row:kArrays)
        for(auto val:row)
            minHeap.push(val);

    while(!minHeap.empty())
    {
        vec.push_back(minHeap.top());
        minHeap.pop();
    }

    return vec;
}
