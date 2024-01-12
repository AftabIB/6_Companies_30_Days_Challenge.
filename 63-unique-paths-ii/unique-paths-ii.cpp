class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& ob,vector<vector<int>> &dp){
        if(i==0 && j==0)
            return 1;
        if(i<0 or j<0)
            return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        int left=0;
        if(j-1>=0 && ob[i][j-1]!=1)
            left=solve(i,j-1,ob,dp);
        int up=0;
        if(i-1>=0 && ob[i-1][j]!=1)    
            up=solve(i-1,j,ob,dp);

        return dp[i][j]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int m = ob.size();
        int n = ob[0].size();
        if(ob[m-1][n-1]==1) return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return solve(m-1,n-1,ob,dp); 
    }
};