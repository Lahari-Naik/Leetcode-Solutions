class Solution {
public:
    bool capacity(vector<int>& w, int d, int m)
    {
        int ans = 1;
        int sum = 0;
        for(int i=0;i<w.size();i++)
        {
            if(sum + w[i] > m)
            {
                sum=w[i];
                ans++;
            }
            else 
            {
                sum += w[i];
            }
        }
        if(ans<=d) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int l = *max_element(weights.begin(),weights.end());
        int h = 0;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            h+=weights[i];
        }
        while(l<=h)
        {
            int m = l + (h-l)/2;
            if(capacity(weights,days,m))
            {
                ans = m;
                h = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        return ans;
    }
};