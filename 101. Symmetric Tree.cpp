// https://leetcode.com/problems/symmetric-tree/

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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        else if(root->left == NULL && root->right == NULL) return true;
        else return Symmetric( root -> left, root ->right);    
    }
    
    bool Symmetric(TreeNode *left, TreeNode *right){
        if(left == NULL && right == NULL) return true;
        if((left == NULL && right != NULL) || (left != NULL && right == NULL) ) return false;
        if(left->val != right->val)  return false;
        else return Symmetric(left->left, right->right) && Symmetric(left->right, right->left);
    }  
};