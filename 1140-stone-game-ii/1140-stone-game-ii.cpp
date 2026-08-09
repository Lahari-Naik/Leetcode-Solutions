class Solution {
public:
    int n;
    vector<int> sum;
    vector<vector<int>> dp;

    int solve(int i, int M, vector<int>& piles)
    {
        if(i == n)
            return 0;

        if(dp[i][M] != -1)
            return dp[i][M];

        int total = 0;
        int ans = 0;

        for(int x = 1; x <= 2 * M && i + x <= n; x++)
        {
            total += piles[i + x - 1];

            int opponent = solve(i + x, max(M, x), piles);

            ans = max(ans, total + (sum[i + x] - opponent));
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles)
    {
        n = piles.size();

        sum.resize(n + 1, 0);

        for(int i = n - 1; i >= 0; i--)
            sum[i] = sum[i + 1] + piles[i];

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1, piles);
    }
};