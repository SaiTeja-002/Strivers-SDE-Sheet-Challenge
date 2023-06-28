#include <bits/stdc++.h> 
int kthLargest(vector<int>& nums, int size, int k)
{
	priority_queue<int, vector<int>> maxHeap(nums.begin(), nums.end());
        
	while(--k)
		maxHeap.pop();

	return maxHeap.top();
}