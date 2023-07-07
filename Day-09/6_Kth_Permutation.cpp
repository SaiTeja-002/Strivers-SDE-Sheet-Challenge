#include<bits/stdc++.h>

string kthPermutation(int n, int k)
{
    string seq = "";

    for (int i=1; i<=n; i++)
        seq += to_string(i);
        
    vector<int> fact(n + 1);
    fact[0] = 1;

    for (int i=1; i<=n; i++)
        fact[i] = fact[i-1]*i;

    k--;
    string ans = "";

    for (int i=n-1; i>=0; i--)
    {
        int index = k/fact[i];
        k %= fact[i];
        ans += seq[index];
        seq.erase(seq.begin() + index);
    }

    return ans;
}
