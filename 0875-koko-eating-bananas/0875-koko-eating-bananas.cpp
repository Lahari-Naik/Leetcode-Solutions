class Solution {
public:
    bool cando(vector<int>& piles, int h, int m)
    {
        long long k = 0;
        for(int i=0;i<piles.size();i++)
        {
            k+=piles[i]/m;
            if(piles[i]%m!=0) k++;
        }
        if(k<=h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(), piles.end());
        int l = 1;
        int ans = 0;
        while(l<=r)
        {
            int m = l + (r-l)/2;
            if(cando(piles,h,m))
            {
                ans = m;
                r = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        return ans;
    }
};