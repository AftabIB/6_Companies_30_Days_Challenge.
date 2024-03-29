class Solution {
public:
    string getHint(string secret, string guess) {
        int cows = 0, bulls = 0;

        vector<int> count(10, 0);
        for(int i=0;i<secret.length();i++)
        {
            int s = secret[i] - '0';
            int g = guess[i] - '0';
            if(s == g)
            {
                bulls++;
            }
            else
            {
                if(count[s]++ < 0)  cows++;
                if(count[g]-- > 0)  cows++; 
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B"; 
    }
};