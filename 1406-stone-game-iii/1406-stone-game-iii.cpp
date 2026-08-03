class Solution {
public:
    int solve(int i, vector<int>& s, vector<int>& dp)
    {
        if(i>=s.size()) return 0;
        if(dp[i]!=INT_MIN) return dp[i];
        int sum = 0;
        for(int j=i;j<i+3 && j<s.size();j++)
        {
            sum+=s[j];
            dp[i] = max(dp[i],sum-solve(j+1,s,dp));
        }
        return dp[i];
    }
    string stoneGameIII(vector<int>& s) {
        int n = s.size();
        vector<int> dp(n,INT_MIN);
        int k = solve(0,s,dp);
        if(k>0)
        {
            return "Alice";
        }
        else if(k<0)
        {
            return "Bob";
        }
        return "Tie";
    }
};