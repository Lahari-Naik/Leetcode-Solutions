class Solution {
public:
    int first(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        int ans = -1;

        while (l <= h) {
            int m = l + (h - l) / 2;

            if (nums[m] == target) {
                ans = m;
                h = m - 1;
            }
            else if (nums[m] < target) {
                l = m + 1;
            }
            else {
                h = m - 1;
            }
        }

        return ans;
    }

    int last(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        int ans = -1;

        while (l <= h) {
            int m = l + (h - l) / 2;

            if (nums[m] == target) {
                ans = m;
                l = m + 1;
            }
            else if (nums[m] < target) {
                l = m + 1;
            }
            else {
                h = m - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums, target), last(nums, target)};
    }
};