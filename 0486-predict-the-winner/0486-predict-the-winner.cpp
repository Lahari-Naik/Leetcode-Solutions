class Solution {
public:
    vector<vector<int>> memo;

    int solve(vector<int>& nums, int i, int j) {
        if (i == j)
            return nums[i];

        if (memo[i][j] != INT_MIN)
            return memo[i][j];

        int pickLeft = nums[i] - solve(nums, i + 1, j);
        int pickRight = nums[j] - solve(nums, i, j - 1);

        return memo[i][j] = max(pickLeft, pickRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memo.assign(n, vector<int>(n, INT_MIN));

        return solve(nums, 0, n - 1) >= 0;
    }
};