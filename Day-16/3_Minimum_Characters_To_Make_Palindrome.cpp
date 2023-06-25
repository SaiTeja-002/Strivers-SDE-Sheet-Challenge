#include<bits/stdc++.h>

int minCharsforPalindrome(string str)
{
	int n = str.size();
	int i=0, j=n-1, count = 0, actualJ = j;

	while(i < j)
	{
		if(str[i] == str[j])
		{
			i++;
			j--;
		}
		else
		{
			count++;
			i = 0;
			actualJ--;
			j = actualJ;
		}
	}	

	return count;
}