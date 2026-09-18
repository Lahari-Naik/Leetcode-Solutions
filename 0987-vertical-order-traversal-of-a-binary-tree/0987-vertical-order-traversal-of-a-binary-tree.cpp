class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> mp;

    void solve(TreeNode* root, int col, int row) {
        if (root == nullptr)
            return;

        mp[col].push_back({row, root->val});

        solve(root->left, col - 1, row + 1);
        solve(root->right, col + 1, row + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == nullptr)
            return {};

        solve(root, 0, 0);

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (auto it : mp) {
            mini = min(mini, it.first);
            maxi = max(maxi, it.first);
        }

        vector<vector<int>> ans;

        for (int i = mini; i <= maxi; i++) {
            if (mp.find(i) != mp.end()) {
                sort(mp[i].begin(), mp[i].end());

                vector<int> temp;

                for (auto x : mp[i]) {
                    temp.push_back(x.second);
                }

                ans.push_back(temp);
            }
        }

        return ans;
    }
};