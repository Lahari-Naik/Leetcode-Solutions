class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& b) {
        int n = b.size();
        const int MOD = 1e9 + 7;
        vector<vector<int>> sum(n, vector<int>(n, -1));
        vector<vector<int>> way(n, vector<int>(n, 0));
        sum[0][0] = 0;
        way[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (b[i][j] == 'X')
                    continue;
                if (i == 0 && j == 0)
                    continue;
                int best = -1;
                if (i > 0)
                    best = max(best, sum[i - 1][j]);
                if (j > 0)
                    best = max(best, sum[i][j - 1]);
                if (i > 0 && j > 0)
                    best = max(best, sum[i - 1][j - 1]);
                if (best == -1)
                    continue;
                int val = 0;
                if (isdigit(b[i][j]))
                    val = b[i][j] - '0';
                sum[i][j] = best + val;
                if (i > 0 && sum[i - 1][j] == best)
                    way[i][j] = (way[i][j] + way[i - 1][j]) % MOD;
                if (j > 0 && sum[i][j - 1] == best)
                    way[i][j] = (way[i][j] + way[i][j - 1]) % MOD;
                if (i > 0 && j > 0 && sum[i - 1][j - 1] == best)
                    way[i][j] = (way[i][j] + way[i - 1][j - 1]) % MOD;
            }
        }
        if (way[n - 1][n - 1] == 0)
            return {0, 0};
        return {sum[n - 1][n - 1], way[n - 1][n - 1]};
    }
};