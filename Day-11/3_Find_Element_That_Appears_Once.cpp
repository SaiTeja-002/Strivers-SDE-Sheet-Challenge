int singleNonDuplicate(vector<int>& nums)
{
	int low=0, high=nums.size()-1;

	while(low < high)
	{
		int mid = low + ((high-low)/2);

		if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
			return nums[mid];

		// mid is even
		if(mid%2 == 0)
		{
			if(nums[mid] == nums[mid+1])
				low = mid+1;
			else
				high = mid-1;
		}
		else	// If mid is odd
		{
			if(nums[mid] == nums[mid-1])
				low = mid+1;
			else
				high = mid-1;
		}
	}

	return nums[low];
}