#include <bits/stdc++.h>

void fun(string s, int index, vector<string>& res)
{
    if(index == s.size())
    {
        res.push_back(s);
        return ;
    }

    for(int i=index; i<s.size(); i++)
    {
        swap(s[index], s[i]);
        fun(s, index+1, res);
    }
}

vector<string> findPermutations(string &s)
{
    vector<string> res;

    fun(s, 0, res);

    return res;
}