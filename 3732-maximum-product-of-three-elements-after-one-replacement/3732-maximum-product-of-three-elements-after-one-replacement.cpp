class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        long long a1 = 1LL * nums[0] * nums[1] * 100000;
        long long a2 = 1LL * nums[0] * nums[n-1] * (-100000);
        long long a3 = 1LL * nums[n-2] * nums[n-1] * 100000;

        return max({a1, a2, a3});
    }
};