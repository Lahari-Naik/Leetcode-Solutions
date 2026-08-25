class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> s(nums.begin(),nums.end());
        int n = *max_element(nums.begin(),nums.end());
        for(int i=1;i<n/k+1;i++)
        {
            if(s.find(k*i)==s.end())
            {
                return k*i;
            }
        }
        return (n/k+1)*k;
    }
};