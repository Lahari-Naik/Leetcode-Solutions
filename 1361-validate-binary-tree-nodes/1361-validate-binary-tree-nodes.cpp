class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return false;

        parent[pv] = pu;
        return true;
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild,
                                 vector<int>& rightChild) {

        DSU dsu(n);
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++) {

            if (leftChild[i] != -1) {

                indegree[leftChild[i]]++;

                if (indegree[leftChild[i]] > 1)
                    return false;

                if (!dsu.unite(i, leftChild[i]))
                    return false;
            }

            if (rightChild[i] != -1) {

                indegree[rightChild[i]]++;

                if (indegree[rightChild[i]] > 1)
                    return false;

                if (!dsu.unite(i, rightChild[i]))
                    return false;
            }
        }

        int roots = 0;

        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                roots++;

        return roots == 1;
    }
};