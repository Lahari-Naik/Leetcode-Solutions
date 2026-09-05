class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr(n,0);
        arr[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            arr[i] = min(arr[i+1],nums[i]);
        }
        int x = nums[0];
        arr[0] = x - arr[0];
        if(arr[0]<=k) return 0;
        for(int i=1;i<n;i++)
        {
            x = max(nums[i],x);
            arr[i] = x - arr[i];
            if(arr[i]<=k) return i;
        }
        return -1;
    }
};