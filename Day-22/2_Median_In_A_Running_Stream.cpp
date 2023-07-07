#include<bits/stdc++.h>

vector<int> findMedian(vector<int> &nums, int n)
{
    vector<int> vec;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i=0; i<n; i++)
    {
        maxHeap.push(nums[i]);

        int temp = maxHeap.top();
        maxHeap.pop();

        minHeap.push(temp);

        if(minHeap.size() > maxHeap.size())
        {
            temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
        }

        if(maxHeap.size() != minHeap.size())  
			vec.push_back(maxHeap.top());

    	else
			vec.push_back((maxHeap.top() + minHeap.top())/2);
    }

    return vec;
}