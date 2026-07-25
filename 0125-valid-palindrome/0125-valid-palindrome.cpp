class Solution {
public:
    bool isPalindrome(string s) {
        string a = "";
        for(char c : s)
        {
            if(isalpha(c))
            {
                a+=tolower(c);
            }
            else if(isdigit(c))
            {
                a+=c;
            }
        }
        string b = a;
        reverse(b.begin(),b.end());
        return a==b;
    }
};