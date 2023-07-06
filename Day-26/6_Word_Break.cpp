bool wordBreak(vector<string> &nums, int n, string &target)
{
    int t = target.size();
    vector<int> dp(t+1, 0);

    dp[t] = 1;

    for(int i=t-1; i>=0; i--)
        for(auto word:nums)
            if(i+word.size()<=t && target.substr(i, word.size())==word && dp[i+word.size()])
                dp[i] = true;

    return dp[0];
}