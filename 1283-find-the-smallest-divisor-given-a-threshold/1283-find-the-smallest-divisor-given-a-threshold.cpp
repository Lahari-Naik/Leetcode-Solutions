class Solution {
public:
    bool divide(vector<int>& nums, int t, int m)
    {
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += (nums[i] + m - 1) / m;
        }
        if(sum<=t) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int t) {
        int l = 1;
        int h = *max_element(nums.begin(),nums.end());
        int ans = 0;
        while(l<=h)
        {
            int m = l + (h-l)/2;
            if(divide(nums,t,m))
            {
                ans = m;
                h = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        return ans;
    }
};