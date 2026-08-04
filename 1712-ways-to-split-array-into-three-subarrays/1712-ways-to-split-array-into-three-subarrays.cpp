class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        int MOD = 1e9+7;
        vector<long long> p(n,0);
        p[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            p[i]=nums[i]+p[i-1];
        }
        int j = 1;
        int k = 1;
        long long ans = 0;
        for(int i=0;i<n-2;i++)
        {
            j = max(j,i+1);
            while(j<n-1 && p[j]-p[i]<p[i])
            {
                j++;
            }
            k = max(k,j);
            while(k<n-1 && p[k]-p[i]<=p[n-1]-p[k])
            {
                k++;
            }
            ans=(ans+k-j)%MOD;
        }
        return ans;
    }
};