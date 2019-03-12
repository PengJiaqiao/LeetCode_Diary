class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int res = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    res++;
                    search(grid, i, j);
                }
            }
        }
        return res;
    }
private:
    void search(vector<vector<char>>& grid, int row, int col) {
        grid[row][col] = 0;
        if(row > 0 && grid[row - 1][col] == '1') search(grid, row - 1, col);
        if(row < grid.size() - 1 && grid[row + 1][col] == '1') search(grid, row + 1, col);
        if(col > 0 && grid[row][col - 1] == '1') search(grid, row, col - 1);
        if(col < grid[0].size() - 1 && grid[row][col + 1] == '1') search(grid, row, col + 1);
        return;
    }
};
