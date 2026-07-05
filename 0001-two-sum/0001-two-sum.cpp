class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int n = nums.size();
        vector<int> v;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            if(mp.count(t-nums[i]))
            {
                v.push_back(mp[t-nums[i]]);
                v.push_back(i);
            }
            mp[nums[i]] = i;
        }
        return v;
    }
};