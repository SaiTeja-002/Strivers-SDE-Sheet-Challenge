#include <bits/stdc++.h> 

struct customComparator
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
};

vector<int> KMostFrequent(int n, int k, vector<int> &nums)
{
    // Frequency, Value
    priority_queue<pair<int, int>, vector<pair<int, int>>, customComparator> pq;
    unordered_map<int, int> frequencyMap;
    vector<int> vec;

    for(auto& num:nums)
        frequencyMap[num]++;

    for(auto& entry:frequencyMap)
        pq.push(make_pair(entry.second, entry.first));

    while(k--)
    {
        vec.push_back(pq.top().second);
        pq.pop();
    }

    sort(vec.begin(), vec.end());

    return vec;
}