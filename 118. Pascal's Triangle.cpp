//https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows == 0) return result;
        for(int i = 0; i < numRows; i++){
            result.push_back(vector<int>());
            result[i].push_back(1);
            if(i > 0){
                for(int j = 1; j < i; j++)
                    result[i].push_back(result[i - 1][j - 1] + result[i - 1][j]);
                result[i].push_back(1);
            }
        }
        return result;
    }
};