class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> sub(9, vector<bool>(9, false));
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int idx = board[i][j] - '1';
                    row[i][idx] = true;
                    col[j][idx] = true;;
                    sub[findSubIdx(i, j)][idx] = true;
                }
            }
        }
        solveSudokuDFS(board, row, col, sub, 0, 0);
    }
private:
    int findSubIdx(int i, int j) {
        vector<int> idx = {0, 1, 2};
        return idx[i / 3] * 3 + idx[j / 3];
    }
    bool solveSudokuDFS(vector<vector<char>>& board, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& sub, int i, int j) {
        if(i == 9) return true;
        if(j == 9) return solveSudokuDFS(board, row, col, sub, i + 1, 0);
        if(board[i][j] == '.') {
            int sub_idx = findSubIdx(i, j);
            for(int k = 0; k < 9; k++) {
                if(row[i][k] == false && col[j][k] == false && sub[sub_idx][k] == false) {
                    board[i][j] = '1' + k;
                    row[i][k] = true;
                    col[j][k] = true;
                    sub[sub_idx][k] = true;
                    if(solveSudokuDFS(board, row, col, sub, i, j + 1)) return true;
                    row[i][k] = false;
                    col[j][k] = false;
                    sub[sub_idx][k] = false;
                }
            }
            board[i][j] = '.';
        }
        else return solveSudokuDFS(board, row, col, sub, i, j + 1);
        return false;
    }
};
