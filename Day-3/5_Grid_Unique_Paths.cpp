#include <bits/stdc++.h> 

int uniquePaths(int m, int n)
{
	int girds = m+n-2;
	double paths=1;

	for(int i=1; i<=m-1; i++)
		paths = paths*(n-1+i)/i;
	
	return (int)paths;
}