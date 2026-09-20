class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] || grid[m-1][n-1]) return -1;
        int dx[] = {0,0,1,-1,1,-1,1,-1};
        int dy[] = {1,-1,1,-1,-1,1,0,0};
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        dist[0][0] = 1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({1,{0,0}});
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int x = it.second.first;
            int y = it.second.second;
            for(int i=0;i<8;i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny] == 1) continue;
                if(d+1<dist[nx][ny])
                {
                    dist[nx][ny] = d+1;
                    pq.push({d+1,{nx,ny}});
                }
            }
        }
        return dist[m-1][n-1] == 1e9 ? -1 : dist[m-1][n-1];
    }
};