class Solution {
public:
    int solve(int i,int j,int& m,int& n,vector<vector<int>>& ob,vector<vector<int>> &dp){
        if(i==m-1 && j==n-1)
            return 1;
        if(i>=m or j>=n)
            return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        int right=0;
        if(j+1<n && ob[i][j+1]!=1)
            right=solve(i,j+1,m,n,ob,dp);
        int down=0;
        if(i+1<m && ob[i+1][j]!=1)    
            down=solve(i+1,j,m,n,ob,dp);

        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int m = ob.size();
        int n = ob[0].size();
        if(ob[0][0]==1) return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return solve(0,0,m,n,ob,dp); 
    }
};