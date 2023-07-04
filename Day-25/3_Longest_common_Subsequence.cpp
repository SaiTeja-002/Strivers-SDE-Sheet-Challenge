int lcs(string s, string t)
{
	int dp[1001][1001];

	for(int i=0; i<s.size(); i++)
	{
		for(int j=0; j<t.size(); j++)
		{
			if(s[i] == t[j])
			{
				dp[i+1][j+1] = dp[i][j]+1;
			}
			else
			{
				dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
			}
		}
	}

	return dp[s.size()][t.size()];
}