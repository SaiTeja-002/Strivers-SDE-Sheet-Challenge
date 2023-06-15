#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m)
{
	long ans=1, longX=x;

	while(n)
	{
		if(n%2)
			ans = ((ans%m)*(longX%m))%m;

		longX = ((longX%m)*(longX%m))%m;
		n /= 2;
	}

	return (int)(ans%m);
}