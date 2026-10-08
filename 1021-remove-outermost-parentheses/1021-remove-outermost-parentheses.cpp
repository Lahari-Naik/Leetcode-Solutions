class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int cnt = 0;
        for(char c : s)
        {
            if(c=='(')
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
            if((cnt!=1 && c=='(') || (cnt!=0 && c==')'))
            {
                ans+=c;
            }
        }
        return ans;
    }
};