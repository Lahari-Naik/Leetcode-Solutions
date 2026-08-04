class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int l = 0;
        int r = n-1;
        int ans = 0;
        while(l<r)
        {
            int k = min(h[r],h[l])*(r-l);
            ans=max(ans,k);
            if(h[l]<h[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
    }
};