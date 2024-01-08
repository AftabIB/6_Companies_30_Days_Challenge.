class Solution {
public:
    vector<vector<int>> directions
    {
        {-1,-1},{-1,0},{-1,1},
        {0,-1},{0,0},{0,1},
        {1,-1},{1,0},{1,1}
    };
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        vector<vector<int>> result(m,vector<int>(n,0));

        for(int i = 0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int neigh_sum = 0;
                int neigh_count = 0;

                for(auto &it : directions)
                {
                    int i_ = i + it[0];
                    int j_ = j + it[1];

                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n)
                    {
                        neigh_sum += img[i_][j_];
                        neigh_count++;
                    }
                }
                result[i][j] = neigh_sum/neigh_count;
            }
        }
        return result; 
    }
};