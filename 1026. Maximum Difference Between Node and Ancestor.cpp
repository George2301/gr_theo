//https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void Diff(TreeNode* root, int mx, int mn, int &res){
        if(!root) return;
        if (mx != INT_MIN) res = max(res, abs(mx - root->val));
        if (mn != INT_MAX) res = max(res, abs(root->val - mn));
        mx = max(mx, root->val);
        mn = min(mn, root->val);
        Diff(root->left, mx, mn, res);
        Diff(root->right, mx, mn, res);
    }
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        int mx = INT_MIN;
        int mn = INT_MAX;
        Diff(root, mx, mn, res);
        return res;
    }
};