class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<
            pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<>> q;
        int m = heights.size();
        int n = heights[0].size();
        if(m == 1 && n == 1) return 0;
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        q.push({0,{0,0}});
        dist[0][0] = 0;
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
         while(!q.empty())
        {
            auto it = q.top();
            q.pop();
            int d = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if(x == m-1 && y == n-1) return d;
            for(int i=0;i<4;i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx>=m || ny >= n) continue;
                int nd = max(d,abs(heights[nx][ny]-heights[x][y]));
                if(nd < dist[nx][ny])
                {
                    dist[nx][ny] = nd;
                    q.push({nd,{nx,ny}});
                }
            }
        }
        return 0;
    }
};