class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i = 0, j = n - 1;
        int steps = 0;
        while(i < j)
        {
            steps += (nums[j] - nums[i]);
            i++;
            j--;
        }
        return steps;
    }
};