/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& p) {
        if (root == nullptr)
            return;
        inorder(root->left, p);
        p.push_back(root->val);
        inorder(root->right, p);
    }
    void recoverTree(TreeNode* root) {
        vector<int> p;
        inorder(root, p);
        int x, y;
        bool found = false;
        for (int i = 0; i < p.size() - 1; i++) {
            if (p[i] > p[i + 1]) {
                if (!found) {
                    x = p[i];
                    found = true;
                }
                y = p[i + 1];
            }
        }
        queue<TreeNode*> q;
        q.push(root);
        int k = 0;
        while (!q.empty() && k < 2) {
            TreeNode* node = q.front();
            q.pop();
            if (node->val == x) {
                node->val = y;
                k++;
            } else if (node->val == y) {
                node->val = x;
                k++;
            }
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
};