class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        vector<bool> col(n, false), diagonal_45(2 * n - 1, false), diagonal_135(2 * n - 1, false);
        vector<vector<string>> res;
        vector<string> tmp;
        string s;
        s.append(n, '.');
        for(int i = 0; i < n; i++) tmp.push_back(s);
        dfs(0, n, col, diagonal_45, diagonal_135, tmp, res);
        return res;
    }
private:
    void dfs(int row, int n, vector<bool>& col, vector<bool>& diagonal_45, vector<bool>& diagonal_135, vector<string>& tmp, vector<vector<string>>& res) {
        if(row == n) {
            res.push_back(tmp);
            return;
        }
        for(int i = 0; i < n; i++) {
            int idx_45 = row + i;
            int idx_135 = row - i + n - 1;
            if(col[i] == false && diagonal_45[idx_45] == false && diagonal_135[idx_135] == false) {
                tmp[row][i] = 'Q';
                col[i] = true;
                diagonal_45[idx_45] = true;
                diagonal_135[idx_135] = true;
                dfs(row + 1, n, col, diagonal_45, diagonal_135, tmp, res);
                tmp[row][i] = '.';
                col[i] = false;
                diagonal_45[idx_45] = false;
                diagonal_135[idx_135] = false;
            }
        }
        return;
    }
};
