class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int l = 0;
        int ans = 0;
        for(int h=0;h<n;h++)
        {
            mp[nums[h]]++;
            while(mp[nums[h]]>k)
            {
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            ans = max(ans,h-l+1);
        }
        return ans;
    }
};