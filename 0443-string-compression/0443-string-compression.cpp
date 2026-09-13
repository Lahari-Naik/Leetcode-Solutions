class Solution {
public:
    vector<char> ans;
    void solve(int n)
    {
        string s;
        if(n==1) return;
        while(n>0)
        {
            s+=('0'+n%10); 
            n/=10;
        }
        for(int i=s.length()-1;i>=0;i--)
        {
            ans.push_back(s[i]);
        }
    }
    int compress(vector<char>& chars) {
        int n = chars.size();
        char c = chars[0];
        int cnt = 0;
        ans.push_back(c);
        for(int i=0;i<n;i++)
        {
            if(chars[i]==c)
            {
                cnt++;
            }
            else
            {
                solve(cnt);
                cnt = 1;
                c = chars[i];
                ans.push_back(c);
            }
        }
        solve(cnt);
        chars = ans;
        return chars.size();
    }
};