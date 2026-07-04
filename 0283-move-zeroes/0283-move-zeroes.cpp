class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = 0;
        while(h<n)
        {
            if(nums[l]==0)
            {
            if(nums[h]!=0)
            {
                swap(nums[l],nums[h]);
                l++;
            }
            }
            else
            {
                l++;
            }
            h++;
        }
    }
};