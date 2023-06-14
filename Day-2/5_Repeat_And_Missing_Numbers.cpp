#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    pair<int,int> p;
    int i, s=0;

    s=(n*(n+1))/2;
    sort(arr.begin(),arr.end());

    int x=0,c=0,d=0;

    for(i=0;i<n;i++)
	{
        c += arr[i];
    }

    for(i=0;i<n;i++)
	{
        if(arr[i]==arr[i+1])
		{
            x=arr[i];
            break;
        }
    }
    d=s+x-c;

    return {d,x};
}