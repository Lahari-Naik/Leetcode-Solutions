class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){return a[1] < b[1];});
        int ans=1;
        int i=0;
        int end = points[0][1];
        while(i<points.size())
        {
            int x2 = points[i][0];
            int y2 = points[i][1];
            if(x2>end)
            {
                ans++;
                end = y2;
            }
            i++;
        }
        return ans;
    }
};