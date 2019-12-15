//https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq, int depth = 0) {
      vector<int> res;
      for (auto c : seq) {
        if (c == '(') res.push_back(depth++ % 2);
        else res.push_back(--depth % 2);        
      }
      return res;
    }
};