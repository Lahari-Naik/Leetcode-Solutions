class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int h=0;
        int ans = 0;
        int cnt = 0;
        while(h<n)
        {
            if(nums[h]==0)
            {
                cnt = 0;
            }
            else
            {
                cnt++;
            }
            ans = max(ans,cnt);
            h++;
        }
        return ans;
    }
};