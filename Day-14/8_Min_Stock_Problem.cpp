// Similar to temperatures, next greater element and next smaller element

#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &prices)
{
    stack<int> indices;
    vector<int> vec(prices.size(), 1);

    for(int i=prices.size()-1; i>=0; i--)
    {
        while(!indices.empty() && prices[i] > prices[indices.top()])
        {
            vec[indices.top()] = indices.top()-i;
            indices.pop();
        }

        indices.push(i);
    }

    while(!indices.empty())
    {
        vec[indices.top()] = indices.top()+1;
        indices.pop();
    }

    return vec;
}