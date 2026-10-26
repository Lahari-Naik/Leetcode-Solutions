class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int cnt = 0;

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0)
                    continue;

                long long sum = 0;

                q.push({i, j});
                sum += grid[i][j];
                grid[i][j] = 0;

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                            grid[nx][ny] != 0) {

                            sum += grid[nx][ny];

                            q.push({nx, ny});
                            grid[nx][ny] = 0;
                        }
                    }
                }

                if (sum % k == 0)
                    cnt++;
            }
        }

        return cnt;
    }
};