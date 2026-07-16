class Solution {
public:
    long long gcd(long long a, long long b)
    {
        if(b==0) return a;
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        int mx = 0;
        for(int i=0;i<n;i++)
        {
            mx = max(mx, nums[i]);
            ans[i] = gcd(nums[i], mx);
        }
        sort(ans.begin(), ans.end());
        long long sum = 0;
        for(int i=0;i<n/2;i++)
        {
            sum += gcd(ans[i], ans[n-i-1]);
        }
        return sum;
    }
};