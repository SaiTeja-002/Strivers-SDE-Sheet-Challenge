#include <bits/stdc++.h> 
int jobScheduling(vector<vector<int>> &jobs)
{
    // unordered_set<int> st;
    // int profit = 0;

    // sort(jobs.begin(), jobs.end(), [](const vector<int> &a, const vector<int> &b){
    //     return a[1] >= b[1];
    // });

    // for(int i=0; i<jobs.size(); i++)
    // {
    //     for(int j=jobs[i][0]-1; j>=0; j--)
    //     {
    //         if(st.find(j) == st.end())
    //         {
    //             st.insert(j);
    //             profit += jobs[i][1];
    //             break;
    //         }
    //     }
    // }

    // return profit;

    int n = jobs.size();

    sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b){
        return a[1] > b[1];
    });
    
    //find maximum deadline
    int maxDead = jobs[0][0];

    for(int i=1; i<n; i++)
        maxDead = max(maxDead, jobs[i][0]);
    
    vector<int> slot(maxDead+1, -1);
    
    int maxProfit=0;
    
    for(int i=0; i<n; i++)
    {
        for(int j=jobs[i][0]; j>0; j--)
        {
            if(slot[j] == -1)
            {
                slot[j] = i;
                maxProfit += jobs[i][1];
                break;
            }
        }
    }

    return maxProfit;
}
