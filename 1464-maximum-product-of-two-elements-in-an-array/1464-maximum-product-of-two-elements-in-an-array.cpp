class Solution {
public:
    int maxProduct(vector<int>& nums) {
        make_heap(nums.begin(),nums.end());
        int a = nums[0]-1;
        nums.erase(nums.begin());
        make_heap(nums.begin(),nums.end());
        int b = nums[0]-1;
        return a*b;
    }
};