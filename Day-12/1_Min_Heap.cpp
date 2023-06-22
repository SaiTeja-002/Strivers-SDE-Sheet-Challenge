#include<bits/stdc++.h>

vector<int> minHeap(int n, vector<vector<int>>& queries)
{
    // n is the size of queries and queries may either contain {0 x} or {1}

    vector<int> vec, ret;
    auto minValPtr = vec.begin();

    for(int i=0; i<n; i++)
    {
        if(queries[i][0] == 0)
        {
            vec.push_back(queries[i][1]);
            minValPtr = min_element(vec.begin(), vec.end());
        }
        else
        {
            ret.push_back(*minValPtr);
            vec.erase(minValPtr);
        }
    }

    return ret;
}