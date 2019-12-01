//https://leetcode.com/problems/validate-binary-search-tree/

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
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        TreeNode *pre = NULL, *post = NULL;
        if(root->left) {
            pre = root->left;
            while(pre->right) 
                pre = pre->right;
            if(pre->val >= root->val) return false;
        }
        if(root->right) {
            post = root->right;
            while(post->left) 
                post = post->left;
            if(post->val <= root->val) return false;
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }
};