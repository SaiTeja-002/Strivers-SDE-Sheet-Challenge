#include<bits/stdc++.h>

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int n, int m, int k) 
{
    if(n>m)
    {
        swap(n, m);
        swap(row1, row2);
    }

    int low, high;

    if(k <= n)
    {
        low = 0;
        high = k;
    }
    else
    {
        low = k-m;
        high = n;
    }

    while(low <= high)
    {
        int mid1 = low+(high-low)/2;
        int mid2 = k-mid1;
        int l1 = (mid1 == 0) ? (INT_MIN) : (row1[mid1-1]);
        int l2 = (mid2 == 0) ? (INT_MIN) : (row2[mid2-1]);
        int r1 = (mid1 == n) ? (INT_MAX) : (row1[mid1]);
        int r2 = (mid2 == m) ? (INT_MAX) : (row2[mid2]);
        
        if(l1 <= r2 && l2 <= r1)
            return max(l1, l2);
        
        else if(l1>r2)
            high = mid1-1;
        
        else
            low = mid1+1;
    }

    return 1;
}