class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans = grid;
        for (int l = 0; l < k; l++) {
            grid = ans;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if(j==0 && i==0)
                    {
                        ans[0][0] = grid[m-1][n-1];
                    }
                    else if(j==0)
                    {
                        ans[i][0] = grid[i-1][n-1];
                    }
                    else 
                    {
                        ans[i][j] = grid[i][j-1];
                    }
                }
            }
        }
        return ans;
    }
};