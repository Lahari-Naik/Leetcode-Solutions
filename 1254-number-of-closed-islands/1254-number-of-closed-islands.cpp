class Solution {
public:
    void solve(int i, int j, int m, int n, vector<vector<int>>& grid)
    {
        queue<pair<int,int>> q;
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        q.push({i,j});
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            grid[x][y] = 1;
            for(int k=0;k<4;k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==0)
                {
                    q.push({nx,ny});
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==0)
            {
                solve(i,0,m,n,grid);
            }
            if(grid[i][n-1]==0)
            {
                solve(i,n-1,m,n,grid);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(grid[0][i]==0)
            {
                solve(0,i,m,n,grid);
            }
            if(grid[m-1][i]==0)
            {
                solve(m-1,i,m,n,grid);
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    cnt++;
                    solve(i,j,m,n,grid);
                }
            }
        }
        return cnt;
    }
};