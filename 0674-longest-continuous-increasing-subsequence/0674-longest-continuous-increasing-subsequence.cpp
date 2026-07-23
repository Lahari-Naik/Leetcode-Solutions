class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int ans = 1;
        for(int h=1;h<n;h++)
        {
            if(nums[h]>nums[h-1])
            {
                ans = max(ans,h-l+1);
            }
            else
            {
                l=h;
            }
        }
        return ans;
    }
};