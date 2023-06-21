int search(int* nums, int n, int target)
{
    int low=0, high=n-1;

    while(low <= high)
    {
        int mid = low + ((high-low)/2);

        if(nums[mid] == target)
            return mid;
        else if(nums[low] <= nums[mid])
        {
            // 4 5 6 7 1
            if(target >= nums[low] && target <= nums[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        else
        {
            // 4 5 1 2 3
            if(target >= nums[mid] && target <= nums[high])
                low = mid+1;
            else
                high = mid-1;
        }
    }

    return -1;
}
