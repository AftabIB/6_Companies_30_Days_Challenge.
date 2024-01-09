class Solution {
public:
    int helper(vector<int>& nums, int k){

        int n=nums.size();
        int i=0, j=0, cur=0, res =0;

        while(j<n)
        {
            if(nums[j]%2)
            cur++;

            while(cur>k)
            {
                if(nums[i]%2)
                cur--;
                i++;
            }

            res += j-i+1;
            j++;
        }
        return res;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {

        return helper(nums,k) - helper(nums, k-1);

    }
};