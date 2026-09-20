class Solution {
public:
    int solve(int i,int n,vector<int>& nums,vector<int>& dp)
    {
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int nottake = solve(i+1,n,nums,dp);
        int take = solve(i+2,n,nums,dp)+nums[i];
        return dp[i] = max(nottake,take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        return max(solve(0,n-1,nums,dp1),solve(1,n,nums,dp2));
    }
};