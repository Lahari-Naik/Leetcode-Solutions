class Solution {
public:
    using ll = long long;

    // nCr capped at limit
    ll C(int n, int r, ll limit) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);

        ll res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if (res > limit) return limit;
        }
        return res;
    }

    // Count distinct permutations of multiset
    ll countWays(vector<int>& cnt, ll limit) {
        int rem = 0;
        for (int x : cnt) rem += x;

        ll ways = 1;
        int left = rem;

        for (int x : cnt) {
            if (x == 0) continue;
            ways *= C(left, x, limit);
            if (ways > limit) return limit;
            left -= x;
        }
        return ways;
    }

    string smallestPalindrome(string s, long long k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26, 0);
        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] % 2)
                mid.push_back(char('a' + i));
        }

        int len = 0;
        for (int x : half) len += x;

        if (countWays(half, k) < k)
            return "";

        string left = "";

        for (int pos = 0; pos < len; pos++) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0) continue;

                half[c]--;

                ll ways = countWays(half, k);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};