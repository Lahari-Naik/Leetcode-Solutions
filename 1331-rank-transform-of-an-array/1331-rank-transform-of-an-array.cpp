class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> s = arr;
        sort(s.begin(), s.end());
        unordered_map<int, int> r;
        int cnt = 1;
        for (int num : s) {
            if (!r.count(num)) {
                r[num] = cnt++;
            }
        }
        for (int &num : arr) {
            num = r[num];
        }
        return arr;
    }
};