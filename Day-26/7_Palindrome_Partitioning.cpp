#include<bits/stdc++.h>

bool isPalindrome(int i, int j, string str)
{
    while(i < j)
        if(str[i++] != str[j--])
            return false;

    return true;
}

int palindromePartitioning(string str) 
{
    int n = str.length();
    vector<int> dp(n+1, 0);

    for(int i=n-1; i>=0;i--)
    {
        int count = INT_MAX;
        for(int j=i; j<n; j++)
        {
            if(isPalindrome(i, j, str))
            {
                int temp = 1 + dp[j+1];
                count = min(temp, count);
            }    
        }

        dp[i] = count;
    }

    return dp[0] - 1;
}