#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& nums1, vector<int>& nums2, int m, int n)
{
	vector<int> result(m + n);
	int i = 0, j = 0, k = 0;

	while (i < m && j < n)
	{
		if (nums1[i] <= nums2[j])
		{
			result[k] = nums1[i];
			i++;
		}
		else
		{
			result[k] = nums2[j];
			j++;
		}

		k++;
	}

	while (i < m)
	{
		result[k] = nums1[i];
		i++;
		k++;
	}

	while (j < n)
	{
		result[k] = nums2[j];
		j++;
		k++;
	}

	return result;
}