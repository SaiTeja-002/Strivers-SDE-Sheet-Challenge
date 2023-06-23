#include<bits/stdc++.h>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> indices;
    vector<int> ns(n, -1);

    for(int i=0; i<n; i++)
    {
        while(!indices.empty() && arr[i] < arr[indices.top()])
        {
            ns[indices.top()] = arr[i];
            indices.pop();
        }

        indices.push(i);
    }

    return ns;
}