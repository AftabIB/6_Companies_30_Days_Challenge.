class Solution {
public:
    int laserCount(string s)
    {
        int total = 0;
        for(auto i : s) 
        {
            if(i == '1')
            {
                total++;
            }
        }
        return total;
            
    }
    int numberOfBeams(vector<string>& bank) {
        int total = 0;
        int start = laserCount(bank[0]);
        int n = bank.size();
        for(int i=1;i<n;i++)
        {
            int curr = laserCount(bank[i]);
            if(curr != 0)
            {
                total += (curr*start);
                start = curr;
            }
        }
        return total;
    }
};