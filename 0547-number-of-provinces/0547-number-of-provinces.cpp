class DSU {
public:
    vector<int> r;
    vector<int> p;
    DSU(int n){
        r.resize(n);
        p.resize(n);
        for(int i=0;i<n;i++){
            r[i] = 0;
            p[i] = i;
        }
    }
    int find(int x)
    {
        if(x!=p[x])
        {
            return find(p[x]);
        }
        return x;
    }
    void unite(int x,int y)
    {
        int px = find(x);
        int py = find(y);
        if(px==py) return;
        if(r[x]>r[y]){
            p[py] = p[px];
        }
        else if(r[y]>r[x]){
            p[px] = p[py];
        }
        else{
            p[py] = p[px];
            r[px]++;
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& con) {
        int n = con.size();
        DSU dsu(n);
        set<int> s;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n && j!=i;j++)
            {
                if(con[i][j]) dsu.unite(i,j);
            }
        }
        for(int i=0;i<n;i++)
        {
            s.insert(dsu.find(i));
        }
        return s.size();
    }
};