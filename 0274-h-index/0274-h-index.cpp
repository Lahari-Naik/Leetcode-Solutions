class Solution {
public:
    int hIndex(vector<int>& c) {
        sort(c.begin(),c.end(),[](int a, int b)
        {
            return a > b;
        });
        if(c[0]==0) return 0;
        int n = c.size();
        int ans = 0;
        int mini = INT_MAX;
        for(int i=0;i<n;i++)
        {
            mini = min(i+1,c[i]);
            ans = max(ans,mini);
        }
        return ans;
    }
};