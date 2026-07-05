class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        vector<int> pos;
        vector<int> neg;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                pos.push_back(i);
            }
            else
            {
                neg.push_back(i);
            }
        }
        int k=0;
        int l=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                ans[i] = nums[pos[k++]];
            }
            else
            {
                ans[i] = nums[neg[l++]];
            }
        }
        return ans;
    }
};