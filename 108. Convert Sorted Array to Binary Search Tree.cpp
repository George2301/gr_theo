//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode* Sort(int b, int e, vector<int>& nums){
        int s = b + (e - b) / 2;
        TreeNode* tree = new TreeNode(nums[s]);
        if(b == e) 
            return tree;
        if(b <= s - 1)
            tree->left = Sort(b, s - 1, nums);
        if(e >= s + 1)
            tree->right = Sort(s + 1, e, nums);
        return tree;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
            return NULL;
        return Sort(0, nums.size() - 1, nums);
    }
};