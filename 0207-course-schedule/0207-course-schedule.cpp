class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        vector<int> in(n,0);
        for(auto it : p)
        {
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                in[adj[i][j]]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(!in[i]) q.push(i);
        }
        int cnt = 0;
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            cnt++;
            for(int k : adj[x])
            {
                in[k]--;
                if(!in[k]) q.push(k);
            }
        }
        return cnt == n;
    }
};