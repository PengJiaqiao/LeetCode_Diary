class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int res = 0;
        for(int i = 0; i < M.size(); i++) {
            for(int j = 0; j < M[0].size(); j++) {
                if(M[i][j] == 1) {
                    res++;
                    search(M, i);
                }
            }
        }
        return res;
    }
private:
    void search(vector<vector<int>>& grid, int row) {
        for(int i = 0; i < grid[row].size(); i++) {
            if(grid[row][i] == 1) {
                if(i == row) grid[row][i] = 0;
                else {
                    grid[row][i] = 0;
                    grid[i][row] = 0;
                    search(grid, i);
                }
            }
        }
        return;
    }
};
