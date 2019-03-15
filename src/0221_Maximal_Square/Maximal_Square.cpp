class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) { // simple brute force. DP is also feasible
        ios::sync_with_stdio(false);
        cin.tie(0);
        int res = 0;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == '1') res = max(res, findSquare(matrix, i, j));
            }
        }
        return res;
    }
private:
    int findSquare(vector<vector<char>>& matrix, int row, int col) {
        int length = 1;
        bool isSquare = true;
        while(row + length < matrix.size() && col + length < matrix[0].size()) {
            for(int i = row; i <= row + length; i++) {
                for(int j = col; j <= col + length; j++) {
                    if(matrix[i][j] == '0') {
                        isSquare = false;
                        break;
                    }
                }
                if(isSquare == false) break;
            }
            if(isSquare == false) break;
            length++;
        }
        return length * length;
    }
};
