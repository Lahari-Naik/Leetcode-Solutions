class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(),strs.end());
        string s = strs[0];
        string v = strs[n-1];
        string ans = "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==v[i])
            {
                ans+=s[i];
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};