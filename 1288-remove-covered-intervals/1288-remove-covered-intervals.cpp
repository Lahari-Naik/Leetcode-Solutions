class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        sort(in.begin(), in.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        for (int i = 0; i < in.size(); i++) {
            if (!ans.empty() && ans.back()[0] <= in[i][0] &&
                ans.back()[1] >= in[i][1]) {
                continue;
            } else {
                ans.push_back(in[i]);
            }
        }
        return ans.size();
    }
};