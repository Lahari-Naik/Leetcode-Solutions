class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (nums[0] == nums[n - 1])
            return 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += abs(nums[n / 2] - nums[i]);
        }
        return ans;
    }
};