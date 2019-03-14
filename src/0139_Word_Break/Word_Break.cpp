class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++) {
            for(string& word : wordDict) {
                if(word.size() > i) continue;
                if(s.substr(i - word.size(), word.size()) == word) dp[i] = dp[i] || dp[i - word.size()];
            }
        }
        return dp[s.size()];
    }
};
