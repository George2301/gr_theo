//https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return {};
        vector<vector<int>> res;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                bool flag_pacific = false;
                bool flag_atlantic = false; 
                bool flag = false;
                pacificAtlanticDFS(matrix, i, j, flag_pacific, flag_atlantic, INT_MAX);
                if(flag_pacific && flag_atlantic){
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
    void pacificAtlanticDFS(vector<vector<int>>& matrix, int y, int x, bool &flag_pacific, bool &flag_atlantic, int former_height){  
        if(flag_pacific && flag_atlantic){
            return;
        }
        if(y < 0 || x < 0){
            flag_pacific = true;
            return;
        }
        if(y >= matrix.size() || x >= matrix[0].size()){
            flag_atlantic = true;
            return;
        }
        if(matrix[y][x] == INT_MAX)
            return;
        if(matrix[y][x] > former_height)
            return;
        former_height = matrix[y][x];
        matrix[y][x] = INT_MAX;
        pacificAtlanticDFS(matrix, y - 1, x, flag_pacific, flag_atlantic, former_height);
        pacificAtlanticDFS(matrix, y + 1, x, flag_pacific, flag_atlantic, former_height);
        pacificAtlanticDFS(matrix, y, x + 1, flag_pacific, flag_atlantic, former_height);
        pacificAtlanticDFS(matrix, y, x - 1, flag_pacific, flag_atlantic, former_height); 
        matrix[y][x] = former_height;
        
    }
};