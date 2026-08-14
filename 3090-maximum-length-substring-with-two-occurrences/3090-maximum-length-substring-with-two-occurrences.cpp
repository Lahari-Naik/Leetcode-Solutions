class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mp;
        int n = s.length();
        int l = 0;
        int ans = 0;
        for(int h=0;h<n;h++)
        {
            mp[s[h]]++;
            while(2<mp[s[h]])
            {
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            ans = max(ans,h-l+1);
        }
        return ans;
    }
};