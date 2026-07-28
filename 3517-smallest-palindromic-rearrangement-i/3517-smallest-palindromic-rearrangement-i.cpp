class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        string k = s.substr(0,n/2);
        sort(k.begin(),k.end());
        string v = k;
        reverse(v.begin(),v.end());
        if(n%2!=0)
        {
            return k+s[n/2]+v;
        }
        return k+v;
    }
};