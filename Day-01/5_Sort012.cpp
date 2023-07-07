#include <bits/stdc++.h> 

void sort012(int *nums, int n)
{
   int low=0, high=n-1, cur=0;

   while(cur <= high)
   {
      if(nums[cur] == 0)
      {
         swap(nums[cur], nums[low]);
         cur++;
         low++;
      }
      else if(nums[cur] == 2)
      {
         swap(nums[cur], nums[high]);
         high--;
      }
      else
         cur++;
   }
}