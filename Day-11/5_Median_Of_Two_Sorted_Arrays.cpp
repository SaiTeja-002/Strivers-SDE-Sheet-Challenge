// double median(vector<int>& arr1, vector<int>& arr2)
// {
// 	vector<int> vec;
// 	int i=0, j=0;
	
// 	while(i<arr1.size() && j<arr2.size())
// 	{
// 		if(arr1[i] <= arr2[j])
// 		{
// 			vec.push_back(arr1[i++]);
// 		}
// 		else
// 		{
// 			vec.push_back(arr2[j++]);
// 		}
// 	}
	
// 	while(i<arr1.size())
// 	{
// 		vec.push_back(arr1[i++]);
// 	}
// 	while(j<arr2.size())
// 	{
// 		vec.push_back(arr2[j++]);
// 	}

// 	int mid = vec.size()/2;

// 	if(vec.size()%2 == 1)
// 		return (double)vec[mid];
	
// 	return (vec[mid-1]+vec[mid])/2.0;

// }

double median(vector<int>& a, vector<int>& b)
{
    if(a.size() > b.size())
		median(b, a);

    int n1 = a.size(), n2 = b.size();
    int low=0, high=n1;

    while(low <= high)
	{
        int m1 = low + (high-low)/2;
        int m2 = (n1+n2+1)/2 - m1;

        int l1 = (m1 == 0) ? (INT_MIN) : (a[m1-1]);
        int l2 = (m2 == 0) ? (INT_MIN) : (b[m2-1]);

        int r1 = (m1 == n1) ? (INT_MAX) : (a[m1]);
        int r2 = (m2 == n2) ? (INT_MAX) : (b[m2]); 

        if(l1<=r2 && l2<=r1)
		{
            if((n1+n2)%2 == 0)
                return ((max(l1, l2)) + (min(r1, r2)))/2.0;
            else
                return max(l1, l2);

        }
		else if(l1>r2)
            high = m1-1;
		else
            low = m1 + 1;
    }
}