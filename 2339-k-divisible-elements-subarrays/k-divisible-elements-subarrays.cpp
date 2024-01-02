class Solution {
public:
    int countDistinct(vector<int>& a, int k, int p) {
        set<vector<int>> s;
        for (int i = 0; i < a.size(); i++) {
            int t = 0;
            vector<int> tmp;
            for (int j = i; j < a.size();j++)
	            {
                t += (a[j] % p == 0);
                if (t <= k) {
                    tmp.push_back(a[j]);
                    s.insert(tmp);
                }
                else
                    break;
            }
        }
        return (int)s.size();
    }
};