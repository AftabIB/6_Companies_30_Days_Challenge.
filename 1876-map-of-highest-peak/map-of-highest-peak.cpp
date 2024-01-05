class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int R = isWater.size();
        int C = isWater[0].size();
        vector<vector<int>> grid(R,vector<int>(C,INT_MAX));
        queue<pair<int,int>> q;

        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(isWater[i][j] == 1)
                {
                    q.push({i,j});
                    grid[i][j] = 0;
                }
            }
        }

        // BFS traversing
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int dr[4] = {0,0,-1,1};
            int dc[4] = {-1,1,0,0};
            for(int i=0;i<4;i++)
            {
                int rr = r+dr[i];
                int cc = c+dc[i];

                if(rr>=0 && rr<R && cc>=0 && cc<C && grid[rr][cc]>1+grid[r][c])
                {
                    grid[rr][cc] = 1 + grid[r][c];
                    q.push({rr,cc});
                }
            }
        }
        return grid;
    }
};