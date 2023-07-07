#include <bits/stdc++.h> 

vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{
    vector<vector<int>> meetings;
    vector<int> ret;

    for(int i=0; i<start.size(); i++)
        meetings.push_back({start[i], end[i], i+1});

    sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b){
        if(a[1] == b[1])
            return a[2] < b[2];
        return a[1] < b[1];
    });

    ret.push_back(meetings[0][2]);
    int prevEnd = meetings[0][1];

    for(int i=1; i<meetings.size(); i++)
    {
        if(meetings[i][0] > prevEnd)
        {
           ret.push_back(meetings[i][2]);
           prevEnd = meetings[i][1];
        }
    }

    return ret;
}