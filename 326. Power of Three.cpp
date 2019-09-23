//https://leetcode.com/problems/power-of-three/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) 
            return false;
        if (pow(3, (log(n)/log(3))) == n)
            return true;
    }
};
