class Solution {
public:
    int minPartitions(string n) { 
        int k = 0;
        for(char c:n)
        {
            k = max(k,c-'0');
        }
        return k;
    }
};