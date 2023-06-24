string longestPalinSubstring(string str)
{
    int n = str.length(), left, right;
    int start=0, end=1;

    for(int i=1; i<n; i++)
    {
        left=i-1;
        right=i;

        while(left>=0 && right<n && str[left]==str[right])
        {
            if(right-left+1 > end)
            {
                start=left;
                end=right-left+1;
            }

            left--;
            right++;
        }

        left = i-1;
        right = i+1;

        while(left>=0 && right<n && str[left]==str[right])
        {
            if(right-left+1 > end)
            {
                start=left;
                end=right-left+1;
            }

            left--;
            right++;
        }
    }

    return str.substr(start, end);
}

