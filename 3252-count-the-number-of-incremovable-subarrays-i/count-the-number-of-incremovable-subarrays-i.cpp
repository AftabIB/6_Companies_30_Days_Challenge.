class Solution {
public:
    bool isIncreSubarray(vector<int> &nums,int start,int end)
    {
        int n = nums.size();
        int prev = 0;
        for(int i = 0;i<n;i++)
        {
            if(i <= end && i >= start)
            {
                continue;
            }
            if(nums[i] <= prev)
            {
                return false;
            }
            prev = nums[i];
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0;i < n; i++)
        {
            for(int j = i;j < n; j++)
            {
                if(isIncreSubarray(nums,i,j))
                {
                    count++;
                }
            }
        }
        return count;
    }
};