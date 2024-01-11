// class Solution {
// public:
//     int solve(vector<int> &nums)
//     {
//         int n = nums.size();
//         int prev = nums[0];
//         int prev2 = 0;
//         for(int i=1;i<n;i++)
//         {
//             int take = nums[i];
//             if(i > 1)   take += prev2;

//             int noTake = 0 + prev;

//             int curr = max(take,noTake);
//             prev2 = prev;
//             prev = curr;
//         }
//         return prev;
//     }
//     int rob(vector<int>& nums) {
//         vector<int> temp1,temp2;
//         int n = nums.size();
//         if(n == 1)  return nums[0];
//         for(int i = 0;i<n;i++)
//         {
//             if(i != 0)  temp1.push_back(nums[i]);
//             if(i != n-1)    temp2.push_back(nums[i]);
//         }
//         return max(solve(temp1),solve(temp2));
//     }
// };

class Solution {
public:
    int maximumNonAdjacentSum(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for(int i=1; i<n; ++i) {
            int pick = nums[i];
            if(i > 1)
                pick += prev2;
            int notPick = prev;

            int curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

    int rob(vector<int>& nums) {
        vector<int> first, last;
        int n = nums.size();

        if(n == 1)
            return nums[0];

        for(int i=0; i<n; ++i) {
            if(i != 0) first.push_back(nums[i]);
            if(i != n-1) last.push_back(nums[i]);
        }

        return max(maximumNonAdjacentSum(first), maximumNonAdjacentSum(last));
    }
};