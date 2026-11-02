class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(nums[0]==nums[n-1]) return 0;
        int ans = 0;
        if(n%2!=0)
        {
            for(int i=0;i<n;i++)
            {
                ans+=abs(nums[n/2]-nums[i]);
            }
        }
        else
        {
            int s1=0,s2=0;
            for(int i=0;i<n;i++)
            {
                s1+=abs(nums[n/2-1]-nums[i]);
            }
            for(int i=0;i<n;i++)
            {
                s2+=abs(nums[n/2]-nums[i]);
            }
            ans = min(s1,s2);
        }
        return ans;
    }
};