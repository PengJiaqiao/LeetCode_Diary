class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        vector<vector<bool>> reached(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    if(search(board, reached, word, i, j, 1)) return true;
                }
            }
        }
        return false;
    }
private:
    bool search(vector<vector<char>>& board, vector<vector<bool>>& reached, string& word, int row, int col, int idx) {
        if(idx == word.size()) return board[row][col] == word[idx - 1];
        reached[row][col] = true;
        if(row > 0 && !reached[row - 1][col] && board[row - 1][col] == word[idx]) {
            if(search(board, reached, word, row - 1, col, idx + 1)) {
                reached[row][col] = false;
                return true;
            }
        }
        if(row < board.size() - 1 && !reached[row + 1][col] && board[row + 1][col] == word[idx]) {
            if(search(board, reached, word, row + 1, col, idx + 1)) {
                reached[row][col] = false;
                return true;
            }
        }
        if(col > 0 && !reached[row][col - 1] && board[row][col - 1] == word[idx]) {
            if(search(board, reached, word, row, col - 1, idx + 1)) {
                reached[row][col] = false;
                return true;
            }
        }
        if(col < board[0].size() - 1 && !reached[row][col + 1] && board[row][col + 1] == word[idx]) {
            if(search(board, reached, word, row, col + 1, idx + 1)) {
                reached[row][col] = false;
                return true;
            }
        }
        reached[row][col] = false;
        return false;
    }
};
