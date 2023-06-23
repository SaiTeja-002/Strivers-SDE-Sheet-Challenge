#include <bits/stdc++.h> 

vector<int> maxMinWindow(vector<int> nums, int n)
{
    stack<int> st;
    vector<int> left(n), right(n), ans(n, INT_MIN);
    left[0] = -1;
    st.push(0);

    for(int i=1; i<n; i++)
    {
        while(!st.empty() && nums[st.top()] >= nums[i])
            st.pop();

        left[i] = (st.empty()) ? (-1) : (st.top());
        st.push(i);
    }

    while(!st.empty())
        st.pop();
    
    right[n-1] = n;
    st.push(n-1);

    for(int i=n-2; i>=0; i--)
    {
        while(!st.empty() && nums[st.top()]>=nums[i])
            st.pop();
        
        right[i] = (st.empty()) ? (n) : (st.top());
        st.push(i);
    }

    for(int i=0; i<n; i++)
    {
        int len = right[i]-left[i]-1;
        ans[len-1] = max(ans[len-1], nums[i]);
    }
    for(int i=n-2; i>=0; i--)
        ans[i] = max(ans[i], ans[i+1]);
    
    return ans;
}