class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        vector<vector<int>> adj(n);
        vector<int> out(n,0);
        for(int i=0;i<g.size();i++)
        {
            for(int j=0;j<g[i].size();j++)
            {
                adj[g[i][j]].push_back(i);
                out[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(out[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(int k : adj[x])
            {
                out[k]--;
                if(out[k]==0) q.push(k);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};