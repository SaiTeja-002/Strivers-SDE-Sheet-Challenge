#include<bits/stdc++.h>

string reverseString(string &str)
{
	string ret = "";
	stack<string> st;
	int i=0;

	while(i < str.size())
	{
		if(str[i] != ' ')
		{
			int j=i;
			for(; j<str.size() && str[j] != ' '; j++);
			string temp = str.substr(i, j-i);
			st.push(temp);
			i = j;
		}
		else
			i++;
	}

	while(!st.empty())
	{
		ret += st.top();
		st.pop();

		if(!st.empty())
			ret += " ";
	}

	return ret;
}