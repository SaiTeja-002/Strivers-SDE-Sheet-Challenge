#include<bits/stdc++.h>

int dp[101][10001];

int fun(int k, int n)
{
    if(n == 1 || n == 0)
        return n;

    if(k==1)
        return n;

    if(dp[k][n] != -1)
       return dp[k][n];

   int i = 1, j = n, ans = INT_MAX;

   while(i<=j)
   {
       int mid = (i+(j-i)/2);

       int below = fun(k-1, mid-1);
       int above = fun(k, n-mid);

       int temp = 1 + max(below, above);

       if(above > below)
           i = mid+1;
       else
           j = mid-1;

       ans = min(ans , temp);
   }

   return dp[k][n] = ans;
}

int cutLogs(int k, int n)
{
    memset(dp, -1, sizeof(dp));
    return fun(k, n);
}