class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>n/2)
            {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};