class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        if(nums[l]<=nums[h]) return nums[l];
        while(l<h)
        {
            int m = l+(h-l)/2;
            if(nums[h]<nums[m])
            {
                l = m+1;
            }
            else
            {
                h = m;
            }
        }
        return nums[l];
    }
};