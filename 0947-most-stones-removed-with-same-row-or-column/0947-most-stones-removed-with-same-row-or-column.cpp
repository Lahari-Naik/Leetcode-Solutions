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
        if (x == p[x])
            return x;
        return find(p[x]);
    }
    void unite(int x, int y) { p[find(x)] = find(y); }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DSU dsu(20002);
        for (int i = 0; i < n; i++) {
            dsu.unite(stones[i][0], stones[i][1] + 10001);
        }
        set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(dsu.find(stones[i][0]));
        }
        return n - s.size();
    }
};