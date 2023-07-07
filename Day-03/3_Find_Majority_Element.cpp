#include <bits/stdc++.h>

int findMajorityElement(int nums[], int n)
{
	unordered_map<int, int> map;

	for(int i=0; i<n; i++)
		if(++map[nums[i]] > n/2)
			return nums[i];

	return -1;
}