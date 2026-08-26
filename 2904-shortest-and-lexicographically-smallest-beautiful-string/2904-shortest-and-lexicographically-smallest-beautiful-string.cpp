class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int l = 0;
        int ones = 0;
        for(char c:s)
        {
            if(c=='1') ones++;
        }
        if(ones<k) return "";
        ones=0;
        string ans="";
        for(int h=0;h<n;h++)
        {
            if(s[h]=='1') ones++;
            while(ones>=k)
            {
                if(ones==k)
                {
                    string temp = s.substr(l,h-l+1);
                    if(ans=="" || ans.length()>temp.length()|| temp.length()==ans.length() && ans>temp)
                    {
                        ans = temp;
                    }
                }
                if(s[l]=='1') ones--;
                l++;
            }
        }
        return ans;
    }
};