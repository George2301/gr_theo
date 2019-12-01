//https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int ans;
    
    int lrm(TreeNode *root)
    {
        if (root == NULL) return 0;
        int l = lrm(root->left);
        int r = lrm(root->right);
        int temp = root->val;
        temp = max(temp, temp + l);
        temp = max(temp, temp + r);
        ans = max(ans, temp);
        return max(root->val, root->val + max(l, r));
    }
    
    int maxPathSum(TreeNode *root) {
        ans = root->val;
        lrm(root);
        return ans;
    }
};