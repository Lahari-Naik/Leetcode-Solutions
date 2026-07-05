class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) return ans;

        int t = 0;
        int b = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        int i = 0, j = 0;

        while (t <= b && l <= r) {
            if (i == t && j == l) {
                while (j < r) {
                    ans.push_back(matrix[i][j]);
                    j++;
                }
                ans.push_back(matrix[i][j]);
                t++;
                i++;
            }
            if (t <= b && i == t && j == r) {
                while (i < b) {
                    ans.push_back(matrix[i][j]);
                    i++;
                }
                ans.push_back(matrix[i][j]);
                r--;
                j--;
            }
            if (l <= r && i == b && j == r) {
                while (j > l) {
                    ans.push_back(matrix[i][j]);
                    j--;
                }
                ans.push_back(matrix[i][j]);
                b--;
                i--;
            }
            if (t <= b && i == b && j == l) {
                while (i > t) {
                    ans.push_back(matrix[i][j]);
                    i--;
                }
                ans.push_back(matrix[i][j]);
                l++;
                j++;
            }
        }

        return ans;
    }
};