class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int x=0;
        int y=0;
        for(int i=0;i<n;i++)
        {
            if(mini>nums[i])
            {
                mini = nums[i];
                x = i;
            }
            if(maxi<nums[i])
            {
                maxi = nums[i];
                y = i;
            }
        }
        int k = 0;
        if(x<y)
        {
            k = min(y+1,n-x);
            k = min(k,n+x-y+1);
        }
        else
        {
            k = min(x+1,n-y);
            k = min(k,n-x+y+1);
        }
        return k;
    }
};