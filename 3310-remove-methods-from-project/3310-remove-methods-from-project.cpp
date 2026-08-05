class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& in) {

        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        vector<int> ans;
        for(int i=0;i<in.size();i++)
        {
            adj[in[i][0]].push_back(in[i][1]);
        }
        queue<int> q;
        q.push(k);
        vis[k]=1;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(int i=0;i<adj[x].size();i++)
            {
                int y=adj[x][i];
                if(vis[y]==0)
                {
                    vis[y]=1;
                    q.push(y);
                }
            }
        }
        for(int i=0;i<in.size();i++)
        {
            if(vis[in[i][0]]==0 && vis[in[i][1]]==1)
            {
                for(int j=0;j<n;j++)
                    ans.push_back(j);
                return ans;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
                ans.push_back(i);
        }
        return ans;
    }
};