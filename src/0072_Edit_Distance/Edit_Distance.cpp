class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = 0;
        for(int i = 1; i <= m; i++) dp[i][0] = i;
        for(int i = 1; i <= n; i++) dp[0][i] = i;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(word1[i] == word2[j]) dp[i + 1][j + 1] = dp[i][j];
                else dp[i + 1][j + 1] = min(dp[i][j], min(dp[i+ 1][j], dp[i][j + 1])) + 1;
            }
        }
        return dp[m][n];
    }
};
