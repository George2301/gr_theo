//https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/

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
    TreeNode* recoverFromPreorder(string S) {
        int index = 0;
        return dfs(S, index, 0);
    }
    
    TreeNode* dfs(string& S, int& index, int level) {
        if (index >= S.length()) return nullptr;

        int curLevel = 0;
        while (S[index] == '-') {
            index++;
            curLevel++;
        }
        if (curLevel < level) {
            index -= curLevel;
            return nullptr;
        }
        

        int num = S[index++] - '0';
        while (S[index] - '0' >= 0 && S[index] - '9' <= 0) {
            num = 10 * num + (S[index++] - '0');
        }
        
        TreeNode* node = new TreeNode(num);
        
        if (curLevel == level) {
            node->left = dfs(S, index, level+1);
            node->right = dfs(S, index, level+1);
        } else if (curLevel > level) {
            node->left = dfs(S, index, curLevel+1);
        }
        
        return node;
    }
};