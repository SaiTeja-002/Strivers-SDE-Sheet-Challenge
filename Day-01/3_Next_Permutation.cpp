#include <bits/stdc++.h> 

int getAnchorIndex(vector<int> permutation)
{
    for(int i=permutation.size()-1; i>=1; i--)
        if(permutation[i-1] < permutation[i])
            return i-1;

    return -1;
}

int findNextLargestNumIndex(vector<int> permutation, int anchorIndex)
{
    for(int i=permutation.size()-1; i>anchorIndex; i--)
    {
        if(permutation[i] > permutation[anchorIndex])
            return i;
    }

    return -1;
}

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    // Step-1: Find the anchor index
    int anchorIndex = getAnchorIndex(permutation);

    // Step-2: Swap the anchor with the least number in the sequence that is greater than permutation[anchorIndex]
    if(anchorIndex == -1)
        reverse(permutation.begin(), permutation.end());
    else
    {
        int swapIndex = findNextLargestNumIndex(permutation, anchorIndex);
        swap(permutation[anchorIndex], permutation[swapIndex]);

        // Step-3: Sort the new sequence in ascending order
        reverse(permutation.begin()+anchorIndex+1, permutation.end());
    }

    return permutation;
}
