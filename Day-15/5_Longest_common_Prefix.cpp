string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    int i = 0;

    while(true)
    {
        char c = arr[0][i];

        for(int j=1; j<n; j++)
            if(i >= arr[j].size() || arr[j][i] != c)
                return ans;
        
        ans += c;
        i++;
    }

    return ans;
}