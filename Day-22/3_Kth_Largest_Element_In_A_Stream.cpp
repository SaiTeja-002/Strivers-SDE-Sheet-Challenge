#include <bits/stdc++.h> 
class Kthlargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;

public:
    Kthlargest(int k, vector<int> &nums)
    {
       size = k;

       for(int i=0; i<k; i++)
       {
            pq.push(nums[i]);

            if(pq.size() > k)
                pq.pop();
       }
    }

    void add(int num)
    {
        pq.push(num);

        if(pq.size()>size)
            pq.pop();
    }

    int getKthLargest()
    {
        return pq.top();
    }
};