class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int i = 0;i<nums.size();i++)
        {
            twos = twos | (ones & nums[i]);
            ones = ones ^ nums[i];
            int common_bits = ~(ones & twos);
            twos &= common_bits;
            ones &= common_bits;
        }
        return ones;
    }
};