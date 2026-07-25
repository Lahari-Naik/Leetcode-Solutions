class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int ans = INT_MAX;
        int sum = 0;
        for(int h=0;h<n;h++)
        {
            sum+=nums[h];
            while(sum>=t)
            {
                ans = min(ans,h-l+1);
                sum-=nums[l];
                l++;
            }
        }
        return ans==INT_MAX ? 0 : ans;
    }
};