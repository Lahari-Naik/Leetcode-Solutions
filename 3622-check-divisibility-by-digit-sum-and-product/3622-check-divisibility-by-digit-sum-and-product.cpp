class Solution {
public:
    bool checkDivisibility(int n) {
        int k = n;
        int p = 1;
        int s = 0;
        while(k>0)
        {
            p*=k%10;
            s+=k%10;
            k/=10;
        }
        if(n%(p+s)==0) return true;
        return false;
    }
};