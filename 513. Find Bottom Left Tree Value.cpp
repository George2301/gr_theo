//https://leetcode.com/problems/find-bottom-left-tree-value/

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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        int res;
        if(!root)
            return res;
        q.push(root);
        int count = 1;
        vector<int> tmp;
        while(!q.empty()){
            tmp.push_back(q.front()->val);
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
            count--;
            if(!count){
                count = q.size();
                res = tmp[0];
                tmp.clear();
            }
        }
        return res;
    }
};