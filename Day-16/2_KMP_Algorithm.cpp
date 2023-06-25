#include <bits/stdc++.h> 
vector<int> constructPrefixTable(const string& pattern)
{
    int m = pattern.length();
    int len=0, i=1;

    vector<int> lps(m, 0);

    while(i < m)
    {
        if(pattern[i] == pattern[len])
        {
            len++;
            lps[i++] = len;
        }
        else
        {
            if(len != 0)
                len = lps[len - 1];
            else
            {
                lps[i++] = 0;
            }
        }
    }

    return lps;
}

bool findPattern(string pattern, string main)
{
    int n = main.length(), m = pattern.length();

    vector<int> lps = constructPrefixTable(pattern);

    int i=0, j=0;

    while(i<n)
    {
        if(main[i] == pattern[j])
        {
            i++;
            j++;
        }

        if(j == m)
            return true;

        if(i<n && main[i] != pattern[j])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return false;

    /* int m = main.size(), p = pattern.size();

    for(int i=0; i<=m-p; i++)
    {
        string str = main.substr(i, p);

        if(str == pattern)
            return true;
    }

    return false; */
}