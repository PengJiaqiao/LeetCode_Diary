class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        if(matrix.size() == 0) return {};
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<bool>> canReachP(row, vector<bool>(col)), canReachA(row, vector<bool>(col));
        vector<pair<int, int>> res;
        pair<int, int> tmp;
        
        for(int i = 0; i < row; i++) {
            dfs(matrix, canReachP, i, 0);
            dfs(matrix, canReachA, i, col - 1);
        }
        for(int i = 0; i < col; i++) {
            dfs(matrix, canReachP, 0, i);
            dfs(matrix, canReachA, row - 1, i);
        }
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(canReachP[i][j] && canReachA[i][j]) {
                    tmp.first = i;
                    tmp.second = j;
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& canReach, int row, int col) {
        if(canReach[row][col]) return;
        canReach[row][col] = true;
        if(row > 0 && matrix[row - 1][col] >= matrix[row][col]) dfs(matrix, canReach, row - 1, col);
        if(row < matrix.size() - 1 && matrix[row + 1][col] >= matrix[row][col]) dfs(matrix, canReach, row + 1, col);
        if(col > 0 && matrix[row][col - 1] >= matrix[row][col]) dfs(matrix, canReach, row, col - 1);
        if(col < matrix[0].size() - 1 && matrix[row][col + 1] >= matrix[row][col]) dfs(matrix, canReach, row, col + 1);
        return;
    }
};
