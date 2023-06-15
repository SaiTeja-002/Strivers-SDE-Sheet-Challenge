#include <bits/stdc++.h>

int subarraysXor(vector<int> &nums, int x)
{
  unordered_map<int, int> map;
  int cpx=0, count = 0;

  for(int i=0; i<nums.size(); i++)
  {
      cpx ^= nums[i];

      if(cpx == x)
        count++;

      if(map.find(cpx^x) != map.end())
          count += map[cpx^x];

      map[cpx]++;
  }

  return count;
}