class Solution {
public:
    vector<int> ans;
    vector<vector<int>> adj;
    string l;
    vector<int> dfs(int node,int parent)
    {
        vector<int> freq(26,0);
        for(int child : adj[node])
        {
            if(child==parent) continue;
            vector<int> childfreq = dfs(child,node);
            for(int i=0;i<26;i++)
            {
                freq[i]+=childfreq[i];
            }
        }
        freq[l[node]-'a']++;
        ans[node] = freq[l[node]-'a'];
        return freq;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        l = labels;
        ans.resize(n);
        adj.resize(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0,-1);
        return ans;
    }
};