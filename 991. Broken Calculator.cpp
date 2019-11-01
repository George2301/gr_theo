//https://leetcode.com/problems/broken-calculator/

class Solution {
public:
    int brokenCalc(int x, int y) {
        if(x >= y) 
            return x - y;
        if(y % 2)
            return brokenCalc(x, y + 1) + 1;
        else
            return brokenCalc(x, y / 2) + 1;
    }
};