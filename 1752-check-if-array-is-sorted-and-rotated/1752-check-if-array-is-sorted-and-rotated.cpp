class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n,0);
        vector<int> v = nums;
        sort(v.begin(),v.end());
        for(int i=0;i<2*n-1;i++)
        {
            ans[i] = v[i%n];
        }
        if(v == nums) return true;
        for(int i=n;i<2*n-1;i++)
        {
            v.erase(v.begin());
            v.push_back(ans[i]);
            if(v == nums) return true;
        }
        return false;
    }
};