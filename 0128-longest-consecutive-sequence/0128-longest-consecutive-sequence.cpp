class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxlen = 1;
        int cnt = 1;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n<2) return n;
        int l = 0;
        for(int h=1;h<n;h++)
        {
            if(nums[h]-nums[h-1]==1)
            {
                cnt++;
            }
            else if(nums[h]-nums[h-1]==0)
            {
                continue;
            }
            else
            {
                cnt = 1;
            }
            maxlen = max(maxlen,cnt);
        }
        return maxlen;
    }
};