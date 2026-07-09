class DSU {
    public:
    vector<int> r;
    vector<int> p;
    DSU(int n) {
        r.resize(n, 0);
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
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return;
        if (r[px] > r[py]) {
            p[py] = px;
        } else if (r[py] > r[px]) {
            p[px] = py;
        } else {
            p[py] = px;
            r[px]++;
        }
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int m,  vector<vector<int>>& q) {
        DSU dsu(n);
        vector<bool> ans;
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1]<=m)
            {
                dsu.unite(i,i-1);
            }
        }
        for(auto& it : q)
        {
            ans.push_back(dsu.find(it[0])==dsu.find(it[1]));
        }
        return ans;
    }
};