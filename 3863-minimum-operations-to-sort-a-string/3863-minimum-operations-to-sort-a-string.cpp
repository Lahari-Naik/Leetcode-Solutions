
class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        string k = s;
        sort(k.begin(), k.end());

        if (k == s)
            return 0;

        if (n == 2)
            return -1;

        char l = k[0];
        char h = k[n - 1];

        if (l == s[0] || h == s[n - 1])
            return 1;

        for (int i = 1; i < n - 1; i++) {
            if (s[i] == l || s[i] == h)
                return 2;
        }

        return 3;
    }
};
