int longestSubSeg(vector<int> &arr , int n, int k)
{
    int maxi = 0, count=0;
    
    for(int i = 0, j = 0; i < n; i++)
    {
        if(arr[i] == 0)
            count++;

        while(count > k)
        {
           if(arr[j] == 0)
               count--;
           j++;
        }

        maxi = max(maxi, i-j+1);
    }

    return maxi;
}