class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0;
        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                middle = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        vector<int> half(26);

        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        int m = n / 2;

        string left;

        for (int pos = 0; pos < m; pos++) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;
                left.push_back(char('a' + c));

                string maxLeft = left;

                for (int x = 25; x >= 0; x--) {
                    maxLeft += string(half[x], char('a' + x));
                }

                string candidate = maxLeft;

                if (n % 2)
                    candidate += middle;

                for (int i = m - 1; i >= 0; i--)
                    candidate += maxLeft[i];

                if (candidate > target) {
                    break;
                }

                left.pop_back();
                half[c]++;
            }

            if (left.size() != pos + 1)
                return "";
        }

        string ans = left;

        if (n % 2)
            ans += middle;

        for (int i = m - 1; i >= 0; i--)
            ans += left[i];

        return ans > target ? ans : "";
    }
};