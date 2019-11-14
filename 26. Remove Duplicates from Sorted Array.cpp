//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int mark = 1;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i - 1])
                nums[mark++] = nums[i]; 
        }
        return min(mark, n);
    }
};