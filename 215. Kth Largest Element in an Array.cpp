//https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (k > nums.size()) return 0;
            sort(nums.begin(), nums.end());
        return nums[nums.size() - (k)];
    }
};