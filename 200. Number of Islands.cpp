//https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    void DeleteNeigbourCell(vector<vector<char>>& grid, int i, int j){
	    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
	    if('0' == grid[i][j]) return;
	    grid[i][j] = '0';
	    DeleteNeigbourCell(grid, i - 1, j);
	    DeleteNeigbourCell(grid, i + 1, j);
	    DeleteNeigbourCell(grid, i, j - 1);
	    DeleteNeigbourCell(grid, i, j + 1);
	}
	int numIslands(vector<vector<char>>& grid) {
		int counter = 0;
		for (int i = 0; i < grid.size(); ++i)
			for (int j = 0; j < grid[i].size(); ++j)
				if ('1' == grid[i][j]){
					counter++;
					DeleteNeigbourCell(grid, i, j);
				}
		return counter;
	}
};