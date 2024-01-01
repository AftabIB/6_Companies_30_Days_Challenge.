class Solution {
public:
    string smallestNumber(string pattern) {
        string ans = "";
        stack<int> st;
        int n = pattern.length();
        for(int i=0;i<=n;i++)
        {
            st.push(i+1);
            if(pattern[i] == 'I' || i==n)
            {
                while(!st.empty())
                {
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }
        return ans;
    }
};