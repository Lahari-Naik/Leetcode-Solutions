class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& hasApple)
    {
        int time = 0;
        for(int child:adj[node])
        {
            if(child == parent) continue;
            int childtime = dfs(child,node,adj,hasApple);
            if(childtime>0 || hasApple[child])
            {
                time+=childtime+2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(0,-1,adj,hasApple);
    }
};