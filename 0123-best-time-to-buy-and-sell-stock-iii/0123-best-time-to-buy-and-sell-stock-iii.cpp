class Solution {
public:
    int solve(int i,int buy,int k,vector<int>& prices,vector<vector<vector<int>>>& dp)
    {
        if(k==0) return 0;
        if(i>=prices.size()) return 0;
        if(dp[i][buy][k]!=-1) return dp[i][buy][k];
        int take,nottake;
        if(buy==0)
        {
            nottake = solve(i+1,0,k,prices,dp);
            take = solve(i+1,1,k,prices,dp)-prices[i];
        }
        else
        {
            nottake = solve(i+1,1,k,prices,dp);
            take = solve(i+1,0,k-1,prices,dp)+prices[i];
        }
        return dp[i][buy][k] = max(take,nottake);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(3,-1)));
        return solve(0,0,2,prices,dp);
    }
};