class Solution {
public:
    int minAddToMakeValid(string s) {
        int op = 0;
        int cnt = 0;
        for(char c:s)
        {
            if(c==')')
            {
                if(op==0) cnt++;
                else op--;
            }
            else if(c=='(')
            {
                op++;
            }
        }
        cnt+=op;
        return cnt;
    }
};