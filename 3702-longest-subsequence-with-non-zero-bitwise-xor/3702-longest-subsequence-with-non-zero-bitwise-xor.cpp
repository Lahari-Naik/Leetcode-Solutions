class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXOR = 0;
        bool hasNonZero = false;
        for(int x : nums) {
            totalXOR ^= x;
            if(x != 0) hasNonZero = true;
        }
        if(!hasNonZero) return 0;       // all zeros
        return (totalXOR != 0) ? nums.size() : nums.size() - 1;
    }
};
