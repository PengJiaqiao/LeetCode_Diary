class Solution {
public:
    void solve(vector<vector<char>>& board) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        if(board.size() <= 2 || board[0].size() <= 2) return; 
        int row_max = board.size() - 1, col_max = board[0].size() - 1;
        for(int row = 0; row <= row_max; row++) {
            if(board[row][0] == 'O') search(board, row, 0);
            if(board[row][col_max] == 'O') search(board, row, col_max);
        }
        for(int col = 1; col < col_max; col++) {
            if(board[0][col] == 'O') search(board, 0, col);
            if(board[row_max][col] == 'O') search(board, row_max, col);
        }
        
        for(int i = 0; i <= row_max; i++) {
            for(int j = 0; j <= col_max; j++) {
                if(board[i][j] == 'N') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
        return;
    }
private:
    void search(vector<vector<char>>& grid, int row, int col) {
        grid[row][col] = 'N';
        if(row > 0 && grid[row - 1][col] == 'O') search(grid, row - 1, col);
        if(row < grid.size() - 1 && grid[row + 1][col] == 'O') search(grid, row + 1, col);
        if(col > 0 && grid[row][col - 1] == 'O') search(grid, row, col - 1);
        if(col < grid[0].size() - 1 && grid[row][col + 1] == 'O') search(grid, row, col + 1);
        return;
    }
};
