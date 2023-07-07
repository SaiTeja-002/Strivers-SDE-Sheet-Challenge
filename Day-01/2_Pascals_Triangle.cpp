#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long int>> triangle;

    for(int i=0; i<n; i++)
    {
        vector<long long int> row(i+1, 1);

        for(int j=1; j<i; j++)
        {
            row[j] = triangle[i-1][j-1]+triangle[i-1][j];
        }

        triangle.push_back(row);
    }

    return triangle;
}
