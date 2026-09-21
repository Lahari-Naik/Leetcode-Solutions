class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k)
    {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for(int x : nums)
        {
            x %= k;

            vector<long long> temp(k, 0);

            // Start a new subarray
            temp[x]++;

            // Extend previous subarrays
            for(int r = 0; r < k; r++)
            {
                temp[(r * x) % k] += dp[r];
            }

            dp = temp;

            for(int r = 0; r < k; r++)
                ans[r] += dp[r];
        }

        return ans;
    }
};