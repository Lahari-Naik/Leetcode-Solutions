class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int,int>> grid;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0) grid.push_back({i,j});
            }
        }
        int z = grid.size();
        if(z==0) return;
        for(int l=0;l<z;l++)
        {
            int r = grid[l].first;
            int c = grid[l].second;
            for(int i=0;i<m;i++)
            {
                matrix[i][c] = 0;
            }
            for(int j=0;j<n;j++)
            {
                matrix[r][j] = 0;
            }
        }
    }
};