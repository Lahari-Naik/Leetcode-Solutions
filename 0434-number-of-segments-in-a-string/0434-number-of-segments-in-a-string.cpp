class Solution {
public:
    int countSegments(string s) {
        if(s.empty()) return 0;
        int cnt = 0;
        if(s[0]!=' ') cnt = 1;
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]==' ' && s[i+1]!=' ') cnt++;
        }
        return cnt;
    }
};