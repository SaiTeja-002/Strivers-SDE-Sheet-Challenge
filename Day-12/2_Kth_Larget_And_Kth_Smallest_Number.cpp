#include<bits/stdc++.h>

vector<int> kthSmallLarge(vector<int> &nums, int n, int k)
{
	sort(nums.begin(), nums.end());
	return {nums[k-1], nums[n-k]};
	// priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
	// priority_queue<int, vector<int>> maxHeap(nums.begin(), nums.end());

	// for(int i=0; i<k-1; i++)
	// {
	// 	minHeap.pop();
	// 	maxHeap.pop();
	// }

	// return {minHeap.top(), maxHeap.top()};
}

