class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> s1,s2;
        for(char c:magazine)
        {
            s1[c]++;
        }
        for(char c:ransomNote)
        {
            s2[c]++;
        }
        for(auto it : s2)
        {
            int c = it.first;
            int x = it.second;
            if(x>s1[c])
            {
                return false;
            }
        }
        return true;
    }
};