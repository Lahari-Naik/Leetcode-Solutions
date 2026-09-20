class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        int n = pre.size();
        vector<vector<int>> adj(num);
        for(int i=0;i<n;i++)
        {
            int x = pre[i][0];
            int y = pre[i][1];
            adj[y].push_back(x);
        }
        vector<int> ind(num,0);
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                ind[adj[i][j]]++;
            }
        }
        queue<int> q;
        for(int i=0;i<num;i++)
        {
            if(ind[i]==0) q.push(i);
        }
        int cnt = 0;
        vector<int> ans;
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            cnt++;
            ans.push_back(x);
            for(auto it : adj[x])
            {
                ind[it]--;
                if(ind[it]==0) q.push(it);
            }
        }
        vector<int> v;
        if(cnt!=num) return v;
        return ans;
    }
};