class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq_map;
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            freq_map[nums[i]]++;
        }

        for (auto it : freq_map) {
            if (it.second == 1) {
                return it.first;
            }
        }
        return -1;
    }
};