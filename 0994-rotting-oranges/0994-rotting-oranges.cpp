class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mini = 0;
        int fresh = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    fresh++;
                }
                else if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        while(!q.empty() && fresh>0)
        {
            int k = q.size();
            int dx[] = {0,0,-1,1};
            int dy[] = {1,-1,0,0};
            for(int i=0;i<k;i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int z=0;z<4;z++)
                {
                    int nx = x+dx[z];
                    int ny = y+dy[z];
                    if(nx>=m || ny>=n || nx<0 || ny<0)
                    {
                        continue;
                    }
                    else
                    {
                        if(grid[nx][ny]==1)
                        {
                            fresh--;
                            grid[nx][ny]=2;
                            q.push({nx,ny});
                        }
                    }
                }
            }
            mini++;
        }
        if(fresh==0) return mini;
        return -1;
    }
};