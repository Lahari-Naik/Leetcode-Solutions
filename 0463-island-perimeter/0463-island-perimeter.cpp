class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    cnt += 4;
                    if (i < m - 1 && grid[i + 1][j] == 1) {
                        cnt -= 2;
                    }
                    if (j < n - 1 && grid[i][j + 1] == 1) {
                        cnt -= 2;
                    }
                }
            }
        }
        return cnt;
    }
};