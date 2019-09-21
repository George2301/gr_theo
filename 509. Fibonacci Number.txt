https://leetcode.com/problems/fibonacci-number/

class Solution {
public:
    int fib(int N) {
        if (N < 2)
            return N;
        else 
            return fib(N - 1) + fib(N - 2);
    }
};