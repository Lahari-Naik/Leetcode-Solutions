class Solution {
public:
    int maxProduct(int n) {
        vector<int> nums;
        while(n>0)
        {
            nums.push_back(n%10);
            n/=10;
        }
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(i!=j)
                {
                    ans = max(ans,nums[i]*nums[j]);
                }
            }
        }
        return ans;
    }
};