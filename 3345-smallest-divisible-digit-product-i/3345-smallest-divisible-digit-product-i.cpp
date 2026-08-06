class Solution {
public:
    int smallestNumber(int n, int t) {
        while(n>0)
        {
            int k = n;
            int x = 1;
            while(k>0)
            {
                x *= k%10;
                k/=10;
            }
            if(x%t==0) 
            {
                return n;
                break;
            }
            n++;
        }
        return -1;
    }
};