class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) { // Dynamic programming
        if(matrix.size() == 0) return 0;
        int row = matrix.size(), col = matrix[0].size(), res = 0;
        vector<int> left(col, 0), right(col, col), height(col, 0);
        for(int i = 0; i < row; i++) {
            int cur_left = 0, cur_right = col;
            for(int j = 0, k = col - 1; j < col; j++, k--) {
                if(matrix[i][j] == '1') {
                    left[j] = max(left[j], cur_left);
                    height[j] += 1;
                }
                else {
                    left[j] = 0;
                    cur_left = j + 1;
                    height[j] = 0;
                }
                if(matrix[i][k] == '1') right[k] = min(right[k], cur_right);
                else{
                    right[k] = col;
                    cur_right = k;
                }
            }
            for(int j = 0; j < col; j++) res = max(res, (right[j] - left[j]) * height[j]);
        }
        return res;
    }
};
