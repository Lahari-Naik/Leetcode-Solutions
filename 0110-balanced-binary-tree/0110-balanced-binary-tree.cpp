/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int l = maxDepth(root->left)+1;
        int r = maxDepth(root->right)+1;
        return max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        if(abs(l-r)>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};