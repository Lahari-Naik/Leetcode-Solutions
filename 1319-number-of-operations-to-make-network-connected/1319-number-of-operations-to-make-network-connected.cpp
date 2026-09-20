class DSU{
public:
    vector<int> r,p;
    DSU (int n)
    {
        r.resize(n,0);
        p.resize(n);
        for(int i=0;i<n;i++)
        {
            p[i] = i;
        }
    }
    int find(int x)
    {
        if(x==p[x]) return x;
        return find(p[x]);
    }
    void unite(int x,int y)
    {
        int px = find(x);
        int py = find(y);
        if(px==py) return;
        if(r[x]>r[y])
        {
            p[py] = px;
        }
        else if(r[y]>r[x])
        {
            p[px] = py;
        }
        else
        {
            p[py] = px;
            r[x]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& con) {
        int k = con.size();
        if(k<n-1) return -1;
        set<int> s;
        DSU dsu(n);
        for(int i=0;i<k;i++)
        {
            dsu.unite(con[i][0],con[i][1]);
        }
        for(int i=0;i<n;i++)
        {
            s.insert(dsu.find(i));
        }
        return s.size()-1;
    }
};