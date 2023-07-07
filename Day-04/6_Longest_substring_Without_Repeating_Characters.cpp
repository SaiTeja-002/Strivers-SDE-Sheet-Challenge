#include <bits/stdc++.h>

int uniqueSubstrings(string input)
{
    if(input.length() == 0)
        return 0;

    unordered_map<char,int> m;
    int i=0, j=0, ans=INT_MIN;

    while(j<input.length())   
    {
        m[input[j]]++;  //increase the frequency of the element as you traverse the string
        
        if(m.size()==j-i+1)  // whem map size is equal to the window size means suppose window size is 3 and map size is also three that means in map all unique characters are their
        {
            ans = max(ans,j-i+1);  //compare the length of the maximum window size
        }
        else if(m.size()<j-i+1)   //if the map size is less than the window size means there is some duplicate present like window size = 3 and map size = 2 means there is a duplicates
        {
            while(m.size()<j-i+1)  //so till the duplicates are removed completely
            {
                m[input[i]]--;   //remove the duplicates
                
                if(m[input[i]]==0)  //if the frequency becomes zero 
                {
                    m.erase(input[i]);//delete it completely
                }

                i++;  //go for next element 
            }
        }
        
        j++;  //go for the next element
    }
    
    return ans;
}