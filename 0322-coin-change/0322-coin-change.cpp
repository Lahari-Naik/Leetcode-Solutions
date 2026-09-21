class Solution {
public:
    int solve(int i, int amt, vector<int>& coins,
              vector<vector<int>>& dp)
    {
        if(amt == 0)
            return 0;

        if(i >= coins.size())
            return 1e9;

        if(dp[i][amt] != -1)
            return dp[i][amt];

        int nottake = solve(i + 1, amt, coins, dp);

        int take = 1e9;

        if(amt >= coins[i])
        {
            take = solve(i, amt - coins[i], coins, dp) + 1;
        }

        return dp[i][amt] = min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amt)
    {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amt + 1, -1));

        int ans = solve(0, amt, coins, dp);

        if(ans >= 1e9)
            return -1;

        return ans;
    }
};