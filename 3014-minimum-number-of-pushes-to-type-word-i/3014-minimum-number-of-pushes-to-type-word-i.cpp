class Solution {
public:
    int minimumPushes(string w) {
        int n = w.length();
        int p = 1;
        int sum = 0;
        while(n>0)
        {
            if(n>=8)
            {
                sum+=8*p;
            }
            else
            {
                sum+=n*p;
            }
            n-=8;
            p++;
        }
        return sum;
    }
};