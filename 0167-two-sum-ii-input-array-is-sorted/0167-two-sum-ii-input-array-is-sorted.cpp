class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int l = 0;
        int r = nums.size()-1;
        while(l<r)
        {
            if(nums[l]+nums[r]<t)
            {
                l++;
            }
            else if(nums[l]+nums[r]>t)
            {
                r--;
            }
            else
            {
                return {l+1,r+1};
            }
        }
        return {-1,-1};
    }
};