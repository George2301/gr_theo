//https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    void Trav(TreeNode* root, vector<int> &res){
        if(root){
            Trav(root->left, res);
            res.push_back(root->val);
            Trav(root->right, res);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        Trav(root, res);
        return res;
    }
};