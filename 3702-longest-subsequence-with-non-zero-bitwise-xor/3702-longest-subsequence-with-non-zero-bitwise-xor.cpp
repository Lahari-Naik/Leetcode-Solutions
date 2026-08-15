class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;
        bool nonZero = false;
        for (int n : nums) {
            x ^= n;
            if (n != 0)
                nonZero = true;
        }
        if (!nonZero)
            return 0;

        if (x != 0)
            return nums.size();
        return nums.size() - 1;
    }
};