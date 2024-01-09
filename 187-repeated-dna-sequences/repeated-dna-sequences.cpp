class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen, repeated;
        vector<string> result;
        for (int i = 0; i + 9 < s.size(); ++i) {
            string ten = s.substr(i, 10);
            if (!seen.insert(ten).second) {
                repeated.insert(ten);
            }
        }
        result.assign(repeated.begin(), repeated.end());
        return result;
    }
};
