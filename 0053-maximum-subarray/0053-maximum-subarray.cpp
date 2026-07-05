class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int csum = nums[0];
        int tsum = nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++)
        {
            csum = max(nums[i],csum+nums[i]);
            tsum = max(tsum,csum);
        }
        return tsum;
    }
};