class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> pos, dig;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                dig.push_back(s[i] - '0');
            }
        }

        int m = dig.size();

        vector<long long> prefSum(m + 1, 0);
        vector<long long> prefNum(m + 1, 0);
        vector<long long> pw(m + 1, 1);

        for (int i = 1; i <= m; i++)
            pw[i] = (pw[i - 1] * 10) % MOD;

        for (int i = 1; i <= m; i++) {
            prefSum[i] = prefSum[i - 1] + dig[i - 1];
            prefNum[i] = (prefNum[i - 1] * 10 + dig[i - 1]) % MOD;
        }

        vector<int> ans;

        for (auto& q : queries) {
            int l = q[0], r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long sum = prefSum[R + 1] - prefSum[L];

            long long num =
                (prefNum[R + 1] - prefNum[L] * pw[len] % MOD + MOD) % MOD;

            ans.push_back(num * sum % MOD);
        }

        return ans;
    }
};