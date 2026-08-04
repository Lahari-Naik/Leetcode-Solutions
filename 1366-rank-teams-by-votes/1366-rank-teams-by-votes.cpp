class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int m = votes.size();
        int n = votes[0].size();
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[votes[0][i]] = vector<int>(n, 0);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[votes[i][j]][j]++;
            }
        }
        string ans = votes[0];
        sort(ans.begin(), ans.end(), [&](char a, char b) {
            for (int i = 0; i < n; i++) {
                if (mp[a][i] != mp[b][i])
                    return mp[a][i] > mp[b][i];
            }
            return a < b;
        });

        return ans;
    }
};