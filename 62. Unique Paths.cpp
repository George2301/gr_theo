//https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int results[m][n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0) results[i][j] = 1;
                else results[i][j] = results[i - 1][j] + results[i][j - 1];
            }
        }
        return results[m - 1][n - 1];
    }
};