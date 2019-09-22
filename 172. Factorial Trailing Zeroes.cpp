https://leetcode.com/problems/factorial-trailing-zeroes/

class Solution {
public:
    int trailingZeroes(int n) {
        int f = 0;
        while (n >= 5){   //0 appear when 2 * 5, 2s more than 5s
            f += n/5;
            n = n/5;
        }
        return f;
    }
};