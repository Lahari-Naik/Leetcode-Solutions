class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push('(');
            } else {
                if (s[i - 1] == '(') {
                    ans += (1 << (st.size() - 1));
                }
                st.pop();
            }
        }

        return ans;
    }
};