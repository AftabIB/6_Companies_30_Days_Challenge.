class Solution {
public:
    int n;
    vector<int> dp;

    int BS(vector<vector<int>> &array,int l,int target)
    {
        int r = n-1;

        int result = n+1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(array[mid][0] >= target)
            {
                result = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return result;
    }

    int solve(vector<vector<int>>& array,int i)
    {
        if(i >= n)
        {
            return 0;
        }

        if(dp[i] != -1)
        {
            return dp[i];
        }

        int getNextJob = BS(array,i+1,array[i][1]);
        int take = array[i][2] + solve(array,getNextJob);
        int noTake = solve(array,i+1);

        return dp[i] = max(take,noTake);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        n = startTime.size();
        dp.resize(n, -1);
        vector<vector<int>> array(n,vector<int>(3, 0));
        
        for (int i = 0; i < n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i]; 
            array[i][2] = profit[i]; 
        }
        
        sort(begin(array), end(array));

        return solve(array,0);
    }
};
