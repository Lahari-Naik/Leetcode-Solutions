class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int cnt = 1;
        int k = n/3;
        if(cnt==k+1) ans.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
            {
                cnt++;
            }
            else
            {
                cnt=1;
            }
            if(cnt==k+1)
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};