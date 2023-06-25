#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2)
{
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    return (str1 == str2);
}