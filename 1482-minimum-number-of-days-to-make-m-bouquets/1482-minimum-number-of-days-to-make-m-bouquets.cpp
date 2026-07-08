class Solution {
public:
    bool bouquet(vector<int>& bloom, int m, int k, int mid)
    {
        int cnt = 0;
        int bouquet = 0;
        int n = bloom.size();
        for(int i=0;i<n;i++)
        {
            if(bloom[i]<=mid)
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }
            if(k==cnt)
            {
                bouquet++;
                cnt = 0;
            }
        }
        if(bouquet>=m) return true;
        return false;
    }
    int minDays(vector<int>& bloom, int m, int k) {
        long long total = 1LL * m * k;
        if (total > bloom.size()) return -1;
        int ans = 0;
        int l = 1;
        int h = *max_element(bloom.begin(),bloom.end());
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            if(bouquet(bloom,m,k,mid))
            {
                ans = mid;
                h = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return ans;
    }
};