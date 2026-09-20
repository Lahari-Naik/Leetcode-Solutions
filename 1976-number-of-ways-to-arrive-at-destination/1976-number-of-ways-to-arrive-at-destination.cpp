class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }

        vector<long long> dist(n,1e18);
        vector<long long> ways(n,0);

        dist[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        pq.push({0,0});

        int MOD = 1e9 + 7;

        while(!pq.empty())
        {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(d > dist[u])
                continue;

            for(auto it : adj[u])
            {
                int v = it.first;
                int w = it.second;

                if(d+w < dist[v])
                {
                    dist[v] = d+w;
                    ways[v] = ways[u];

                    pq.push({d+w,v});
                }
                else if(d+w == dist[v])
                {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n-1] % MOD;
    }
};