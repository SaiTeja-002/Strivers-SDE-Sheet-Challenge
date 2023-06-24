#include <bits/stdc++.h>

int atoi(string str)
{
    int sign=1;
    int num=0;

    for(char& ch:str)
    {
        if(isdigit(ch))
        {
            num *= 10;
            num += ch - '0';
        }
        if(ch == '-')
            sign = -1;
    }

    return (sign*num);
}