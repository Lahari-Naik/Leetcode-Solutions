class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int x = *min_element(nums1.begin(),nums1.end());
        int even = 0;
        for(int i=0;i<n;i++)
        {
            if(nums1[i]%2==0)
            {
                even++;
            }
        }
        if(x%2==0 && even!=n) return false;
        return true;
    }
};