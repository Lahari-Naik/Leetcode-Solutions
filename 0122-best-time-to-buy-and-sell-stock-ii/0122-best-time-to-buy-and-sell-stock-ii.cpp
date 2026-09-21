class Solution {
public:
    int solve(int i,int buy,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int take,nottake;
        if(buy==0)
        {
            nottake = solve(i+1,0,prices,dp);
            take = solve(i+1,1,prices,dp)-prices[i];
        }
        else
        {
            nottake = solve(i+1,1,prices,dp);
            take = solve(i+1,0,prices,dp)+prices[i];
        }
        return dp[i][buy] = max(nottake,take);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,0,prices,dp);
    }
};