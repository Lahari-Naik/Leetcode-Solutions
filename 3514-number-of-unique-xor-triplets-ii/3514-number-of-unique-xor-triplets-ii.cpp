class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> v(nums.begin(), nums.end());
        unordered_set<int> p;
        for (int x : v) {
            for (int y : v) {
                p.insert(x ^ y);
            }
        }
        unordered_set<int> ans;
        for (int xy : p) {
            for (int z : v) {
                ans.insert(xy ^ z);
            }
        }
        return ans.size();
    }
};