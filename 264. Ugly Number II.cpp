//https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
    int nthUglyNumber(int n) {
      int nums[n];
        set<long long> seen;
        priority_queue<long long, vector<long long>, greater<long long>> heap;
        seen.insert(1);
        heap.push(1);

        long currUgly, newUgly;
        int primes[]={2, 3, 5};
        for(int i = 0; i < n; ++i) {
          currUgly = heap.top();
            heap.pop();
          nums[i] = (int)currUgly;
          for(int j : primes) {
            newUgly = currUgly * j;
            if (seen.find(newUgly)==seen.end()) {
              seen.insert(newUgly);
              heap.push(newUgly);
            }
          }
        }
        return nums[n - 1];
    }
};