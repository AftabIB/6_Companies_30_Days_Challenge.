class Solution {
public:
    // int solve(int index,vector<int> &nums,vector<int> &dp)
    // {
    //     //base case 
    //     if(index == 0)
    //         return nums[index];
        
    //     if(index < 0)
    //         return 0;

    //     if(dp[index] != -1)
    //         return dp[index];

    //     int take = nums[index] + solve(index - 2,nums,dp);
    //     int notTake = 0 + solve(index - 1,nums,dp);

    //     return dp[index] = max(take,notTake);
    // }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        // if (n == 0) return 0;
        // vector<int> dp(n);
        // dp[0] = nums[0];
        // for(int i = 1; i < n; i++) {
        //     int take = nums[i];
        //     if(i > 1) {
        //         take += dp[i - 2];
        //     }
        //     int noTake = dp[i - 1];
        //     dp[i] = max(take, noTake);
        // }
        // return dp[n - 1];
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1;i<n;i++)
        {
            int take = nums[i];
            if(i > 1)
                take += prev2;
            
            int noTake = 0 + prev;

            int curr = max(take,noTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};