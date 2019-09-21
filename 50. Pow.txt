https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        double a;
        if (n == 0) return 1.0;
        a = myPow(x , n/2);
        if (n % 2 == 0) return a * a;
        else if (n > 0) return x * a * a;
             else return a * a / x;
    }
};