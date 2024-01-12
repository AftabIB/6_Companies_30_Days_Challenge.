class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char,pair<int,string>> mp;
        for(auto it:s){
            mp[it].first++;
            mp[it].second.push_back(it);
        }
        set<pair<int,string>> st;
        for(auto it:mp){
            st.insert({it.second.first,it.second.second});
        }
        for(auto it=st.rbegin();it!=st.rend();++it){
            ans+=(it->second);
        }
        return ans;        
    }
};