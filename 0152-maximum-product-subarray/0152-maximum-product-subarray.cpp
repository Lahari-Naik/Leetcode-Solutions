class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int mini = nums[0];
        int maxi = nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]<0) swap(mini,maxi);
            mini = min(nums[i],mini*nums[i]);
            maxi = max(nums[i],maxi*nums[i]);
            ans = max(maxi,ans);
        }
        return ans;
    }
};