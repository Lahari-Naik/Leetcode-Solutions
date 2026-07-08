class Solution {
public:
    int split(vector<int>& nums, int m)
    {
        int p = 1;
        long long sum = 0;
        for(int n : nums)
        {
            if(sum+n<=m)
            {
                sum+=n;
            }
            else
            {
                p++;
                sum = n;
            }
        }
        return p;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *max_element(nums.begin(),nums.end());
        int h = 0;
        for(int i=0;i<n;i++) h+=nums[i];
        while(l<=h)
        {
            int m = l+(h-l)/2;
            if(split(nums,m)>k)
            {
                l = m+1;
            }
            else
            {
                h=m-1;
            }
        }
        return l;
    }
};