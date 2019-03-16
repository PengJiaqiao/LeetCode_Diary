class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> sub(9, vector<bool>(9, false));
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int idx = board[i][j] - '1', sub_idx = findSubIdx(i, j);
                    if(row[i][idx] == true) return false;
                    else row[i][idx] = true;
                    if(col[j][idx] == true) return false;
                    else col[j][idx] = true;
                    if(sub[sub_idx][idx] == true) return false;
                    else sub[sub_idx][idx] = true;
                }
            }
        }
        return true;
    }
private:
    int findSubIdx(int i, int j) {
        vector<int> idx = {0, 1, 2};
        return idx[i / 3] * 3 + idx[j / 3];
    }
};
