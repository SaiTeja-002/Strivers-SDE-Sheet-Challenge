#include <bits/stdc++.h> 

void fun(int index, string t, string &s, unordered_map<string, int> &mp, vector<string> &ans)
{
    if(index==s.length())
    {
        ans.push_back(t);
        return ;
    }

    string a = "";

    for(int i=index; i<s.length(); i++)
    {
        a += s[i];
        if(mp.find(a) != mp.end())
        {
            if(t.length() == 0)
              fun(i+1, t+a, s, mp, ans);
            else
              fun(i+1, t+" "+a, s, mp, ans);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &words)
{
    unordered_map<string, int> mp;

    for(auto word:words)
      mp[word]++;

    vector<string> ans;
    string t = "";

    fun(0, t, s, mp, ans);

    return ans;
}