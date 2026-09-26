class Solution {
public:
    string evaluate(string s, vector<vector<string>>& know) {
        unordered_map<string,string> mp;
        for(auto it : know)
        {
            mp[it[0]] = it[1];
        }
        int n = s.length();
        string ans = "";
        int i = 0;
        string k = "";
        int l = 0;
        int r = 0;
        bool flag = false;
        while(i<n)
        {
            if(s[i]=='(')
            {
                l = i+1;
                flag = true;
            }
            else if(s[i]==')')
            {
                r = i-1;
                flag = false;
                string k = s.substr(l,r-l+1);
                if(mp.find(k)==mp.end())
                {
                    ans+='?';
                }
                else
                {
                    ans+=mp[k];
                }
            }
            else if(!flag)
            {
                ans+=s[i];
            }
            i++;
        }
        return ans;
    }
};