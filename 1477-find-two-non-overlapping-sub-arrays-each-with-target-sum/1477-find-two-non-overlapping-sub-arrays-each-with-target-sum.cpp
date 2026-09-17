class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int t) {
        int n = arr.size();
        vector<int> best(n, INT_MAX);
        int l = 0;
        int sum = 0;
        int ans = INT_MAX;
        for(int h = 0; h < n; h++)
        {
            sum += arr[h];
            while(sum > t)
            {
                sum -= arr[l];
                l++;
            }
            if(h > 0)
                best[h] = best[h - 1];
            if(sum == t)
            {
                int len = h - l + 1;
                if(l > 0 && best[l - 1] != INT_MAX)
                {
                    ans = min(ans, len + best[l - 1]);
                }
                best[h] = min(best[h], len);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};