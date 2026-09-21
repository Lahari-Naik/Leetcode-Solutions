class Solution {
public:
    int solve(int i, int amt, vector<int>& coins,
              vector<vector<int>>& dp)
    {
        if(amt == 0)
            return 1;

        if(i >= coins.size())
            return 0;

        if(dp[i][amt] != -1)
            return dp[i][amt];

        int nottake = solve(i + 1, amt, coins, dp);

        int take = 0;

        if(amt >= coins[i])
        {
            take = solve(i, amt - coins[i], coins, dp);
        }

        return dp[i][amt] = take+nottake;
    }

    int change(int amt,vector<int>& coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amt + 1, -1));
        int ans = solve(0, amt, coins, dp);
        return ans;
    }
};