class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int maxfreq = 0;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            maxfreq = max(maxfreq,mp[nums[i]]);
        }
        for(auto it : mp)
        {
            if(it.second == maxfreq) ans+=maxfreq;
        } 
        return ans;
    }
};