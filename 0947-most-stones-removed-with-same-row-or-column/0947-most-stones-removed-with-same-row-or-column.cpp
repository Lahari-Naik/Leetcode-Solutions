class DSU {
public:
    vector<int> p;
    DSU(int n) {
        p.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }
    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
    void unite(int x, int y) { p[find(x)] = find(y); }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu(20002);
        for (auto& s : stones) {
            dsu.unite(s[0], s[1] + 10001);
        }
        unordered_set<int> con;
        for (auto& s : stones) {
            con.insert(dsu.find(s[0]));
        }
        return stones.size() - con.size();
    }
};