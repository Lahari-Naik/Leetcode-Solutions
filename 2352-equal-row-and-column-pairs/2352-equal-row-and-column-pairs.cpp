class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> rows;

        for (auto& row : grid)
            rows[row]++;

        int ans = 0;
        int n = grid.size();

        for (int col = 0; col < n; col++) {
            vector<int> column;

            for (int row = 0; row < n; row++)
                column.push_back(grid[row][col]);

            ans += rows[column];
        }

        return ans;
    }
};