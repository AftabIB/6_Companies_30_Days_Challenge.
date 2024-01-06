class Solution {
public:
    int n;
    unordered_map<int, int> memo;

    int BS(vector<vector<int>>& array, int target) {
        int l = 0, r = n - 1;
        int result = n + 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (array[mid][0] >= target) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }

    int solve(vector<vector<int>>& array, int i) {
        if (i >= n) {
            return 0;
        }

        if (memo.find(i) != memo.end()) {
            return memo[i];
        }

        int getNextJob = BS(array, array[i][1]);
        int take = array[i][2] + solve(array, getNextJob);
        int noTake = solve(array, i + 1);

        memo[i] = max(take, noTake);
        return memo[i];
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        n = startTime.size();
        vector<vector<int>> array(n, vector<int>(3, 0));

        for (int i = 0; i < n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }

        sort(begin(array), end(array));

        return solve(array, 0);
    }
};
