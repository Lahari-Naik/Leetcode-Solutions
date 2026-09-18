class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int ans = 0;
        int sum = 0;
        for(int h=0;h<n;h++)
        {
            sum+=nums[h];
            while(sum<h-l)
            {
                sum-=nums[l];
                l++;
            }
            if(sum==h-l)
            {
                ans = max(sum,ans);
            }
        }
        if(sum==n) return sum-1;
        return ans;
    }
};