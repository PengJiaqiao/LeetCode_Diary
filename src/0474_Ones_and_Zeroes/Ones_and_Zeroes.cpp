class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> res(m + 1, vector<int>(n + 1, 0));
        for(string str : strs) {
            pair<int, int> tmp = findZeroAndOne(str);
            if(tmp.first > m || tmp.second > n) continue;
            for(int i = m; i >= tmp.first; i--) {
                for(int j = n; j >= tmp.second; j--) res[i][j] = max(res[i][j], res[i - tmp.first][j - tmp.second] + 1);
            }
        }
        return res[m][n];
    }
private:
    pair<int, int> findZeroAndOne(string& s) {
        pair<int, int> res;
        int zero = 0, one = 0;
        for(char num : s) {
            if(num == '0') zero++;
            else one++;
        }
        res.first = zero;
        res.second = one;
        return res;
    }
};
