class Solution {
public:
    bool solve(int i, int t, vector<vector<int>>& dp, vector<int>& nums)
    {
        if(t == 0)
            return true;

        if(i >= nums.size() || t < 0)
            return false;

        if(dp[i][t] != -1)
            return dp[i][t];

        bool nottake = solve(i + 1, t, dp, nums);

        bool take = solve(i + 1, t - nums[i], dp, nums);

        return dp[i][t] = take || nottake;
    }

    bool canPartition(vector<int>& nums)
    {
        int n = nums.size();
        int total = 0;

        for(int i = 0; i < n; i++)
            total += nums[i];

        if(total % 2 != 0)
            return false;

        int t = total / 2;

        vector<vector<int>> dp(n, vector<int>(t + 1, -1));

        return solve(0, t, dp, nums);
    }
};