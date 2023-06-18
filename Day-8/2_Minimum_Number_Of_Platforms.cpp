#include<bits10_1.h>/stdc++.h>

int calculateMinPatforms(int at[], int dt[], int n)
{
    sort(at, at+n);
    sort(dt, dt+n);

    int i=0, j=0, maxi=0, platforms=0;

    while(i<n && j<n)
    {
        if(at[i] <= dt[j])
        {
            i++;
            platforms++;
        }
        else
        {
            j++;
            platforms--;
        }

        maxi = max(platforms, maxi);
    }
    
    return maxi;
}