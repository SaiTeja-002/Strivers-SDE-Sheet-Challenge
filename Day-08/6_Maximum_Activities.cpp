#include<bits/stdc++.h>

int maximumActivities(vector<int> &start, vector<int> &finish)
{
    vector<vector<int>> activities;
    int count=0;

    for(int i=0; i<start.size(); i++)
        activities.push_back({start[i], finish[i]});

    sort(activities.begin(), activities.end(), [](const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    });

    int prevEnd = activities[0][1];
    count++;

    for(int i=1; i<activities.size(); i++)
    {
        if(activities[i][0] >= prevEnd)
        {
            prevEnd = activities[i][1];
            count++;
        }
    }

    return count;
}