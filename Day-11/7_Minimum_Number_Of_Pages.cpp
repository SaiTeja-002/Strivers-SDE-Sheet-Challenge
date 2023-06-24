#include <bits/stdc++.h> 
bool fun(int n, int m, vector<int>& arr, long long int mid)
{
	long long int count = 1, sum = 0;
	
	for(int i=0; i<m; i++)
	{
		if(sum + arr[i] <= mid)
			sum += arr[i];
		else
		{
			count++;

			if(count>n || arr[i] > mid)
				return false;
			else
				sum = arr[i];
		}
	}

	return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int>time) 
{
	long long int low = 0, sum = 0;
	
	for(int i=0; i<time.size(); i++)
		sum += time[i];
	
	long long int high = sum, ans = -1;
	
	while(low <= high)
	{
		long long int mid = low+((high-low)/2);

		if(fun(n, m, time, mid))
		{
			ans = mid;
			high = mid-1;
		}
		else
			low=mid+1;
	}

	return ans;
}