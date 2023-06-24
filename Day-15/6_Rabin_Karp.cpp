vector<int> stringMatch(string text, string pattern)
{
    vector<int> positions;
    int n = text.length(), m = pattern.length();

    for (int i=0; i<=n-m; i++)
    {
        bool match = true;

        for(int j=0; j<m; j++)
        {
            if(text[i+j] != pattern[j])
            {
                match = false;
                break;
            }
        }

        if (match)
            positions.push_back(i + 1);
    }

    return positions;
}