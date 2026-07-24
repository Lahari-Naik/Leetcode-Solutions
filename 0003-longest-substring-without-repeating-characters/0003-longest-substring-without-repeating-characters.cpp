class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int maxlen = 0;
        unordered_map<char,int> mp;
        for(int h=0;h<s.length();h++)
        {
            mp[s[h]]++;
            while(h-l+1>mp.size())
            {
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            maxlen = max(maxlen,h-l+1);
        }
        return maxlen;
    }
};