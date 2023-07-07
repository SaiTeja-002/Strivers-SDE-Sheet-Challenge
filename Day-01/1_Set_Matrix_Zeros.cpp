#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// TC: O(m*n) SC: O(m+n)
	int m = matrix.size(), n = matrix[0].size();
	unordered_set<string> st;

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(matrix[i][j] == 0)
			{
				st.insert("R"+to_string(i));
				st.insert("C"+to_string(j));
			}
		}
	}

	for(string pos : st)
	{
		if(pos[0] == 'R')
		{
			pos.erase(0, 1);
			int row = stoi(pos);

			for(int i=0; i<n; i++)
				matrix[row][i] = 0;
		}
		else
		{
			pos.erase(0, 1);
			int col = stoi(pos);

			for(int i=0; i<m; i++)
				matrix[i][col] = 0;
		}
	}
}