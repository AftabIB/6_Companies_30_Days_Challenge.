class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it : nums)
        {
            mp[it]++;
        } 

        int ans  = 0;
        for(auto i : mp)
        {
            if(i.second == 1)
                return -1;
            
            ans += (i.second)/3;

            if(i.second % 3)
                ans++;
        }
        return ans;
    }
};