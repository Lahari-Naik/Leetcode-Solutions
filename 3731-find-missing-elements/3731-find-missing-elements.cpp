class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l = nums[0]+1;
        int i=1;
        while(i<n)
        {
            if(l==nums[i])
            {
                l++;
                i++;
            }
            else
            {
                ans.push_back(l);
                l++;
            }
        }
        return ans;
    }
};