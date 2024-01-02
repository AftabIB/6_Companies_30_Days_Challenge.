class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> arr;
        unordered_map<int,int> freq;

        for(auto el : nums)
        {
            freq[el]++;
            if(arr.size() < freq[el])
            {
                arr.push_back({});   
            }
            arr[freq[el] - 1].push_back(el);
        }
        return arr;
    }
};