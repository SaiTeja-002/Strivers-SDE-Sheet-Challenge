#include <bits/stdc++.h> 

int maximumProfit(vector<int> &prices)
{
    int minIndex=0, diff=0;

    for(int i=0; i<prices.size(); i++)
    {
        minIndex = (prices[i] < prices[minIndex]) ? (i) : (minIndex);
        diff = max(diff, prices[i]-prices[minIndex]);
    }

    return diff;
}