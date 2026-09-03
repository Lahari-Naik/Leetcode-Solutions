class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> arr = nums1;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int even = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]%2==0)
            {
                even++;
            }
        }
        if(arr[0]%2==0 && even!=n) return false;
        return true;
    }
};