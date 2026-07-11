class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> vis;

    void dfs(int node, int& vertices, int& degreeSum) {
        vis[node] = true;
        vertices++;
        degreeSum += graph[node].size();

        for (int nei : graph[node]) {
            if (!vis[nei])
                dfs(nei, vertices, degreeSum);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        graph.resize(n);
        vis.assign(n, false);

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {

                int vertices = 0;
                int degreeSum = 0;

                dfs(i, vertices, degreeSum);

                int edgeCount = degreeSum / 2;

                if (edgeCount == vertices * (vertices - 1) / 2)
                    ans++;
            }
        }

        return ans;
    }
};