vector<int> Making_Z_Table(string main)
{
	int n=main.length(), l=0, r=0;
	vector<int> z(n, 0);

	for(int i=1; i<n; i++)
	{
		if(i>r)
		{
			l = r = i;

			while(r<n && main[r] == main[r - l])
				r++;
			
			z[i] = r-l;
			r--;
		}
		else
		{
			int index = i-l;

			if(i+z[index] <= r)
				z[i] = z[index];
			else
			{
				l = i;

				while(r<n && main[r] == main[r-l])
					r++;
				
				z[i] = r-l;
				r--;
			}
		}
	}
	
	return z;   
}


int zAlgorithm(string main, string pattern, int n, int m)
{
    string total = pattern + "$" + main;
    
    vector<int> zTable = Making_Z_Table(total), ans;
    
    for(int i=0; i<zTable.size(); i++)
    {
        if(zTable[i] == pattern.length())
        {
            int val = i - pattern.length() - 1;
            ans.push_back(val);
        }
    }
    
    return (int)ans.size();

	/* int count = 0;

	for(int i=0; i<=m-p; i++)
	{
		string str = main.substr(i, p);
		count += (str == pattern) ? (1) : (0);
	}

	return count; */
}
