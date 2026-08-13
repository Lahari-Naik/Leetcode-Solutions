class Solution {
public:
    struct Node {
        int len;
        int pref;
        int suff;
        int ans;
        char left;
        char right;
    };

    vector<Node> tree;
    string s;

    Node merge(Node a, Node b) {
        Node c;

        c.len = a.len + b.len;
        c.left = a.left;
        c.right = b.right;

        c.pref = a.pref;
        c.suff = b.suff;

        c.ans = max(a.ans, b.ans);

        if (a.right == b.left) {
            c.ans = max(c.ans, a.suff + b.pref);

            if (a.pref == a.len)
                c.pref = a.len + b.pref;

            if (b.suff == b.len)
                c.suff = b.len + a.suff;
        }

        return c;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int pos) {
        if (l == r) {
            tree[node] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid) {
            update(2 * node, l, mid, pos);
        } else {
            update(2 * node + 1, mid + 1, r, pos);
        }

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    vector<int> longestRepeating(string str, string queryCharacters,
                                 vector<int>& queryIndices) {
        s = str;

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {
            int pos = queryIndices[i];

            s[pos] = queryCharacters[i];

            update(1, 0, n - 1, pos);

            ans.push_back(tree[1].ans);
        }

        return ans;
    }
};