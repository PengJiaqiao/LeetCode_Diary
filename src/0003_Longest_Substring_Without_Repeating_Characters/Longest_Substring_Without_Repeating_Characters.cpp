class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        if(s.size() == 0) return 0;
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            vector<bool> reached(128, false);
            int j;
            for(j = i; j < s.size(); j++) {
                if(reached[s[j]] == false) reached[s[j]] = true;
                else break;
            }
            res = max(res, j - i);
        }
        return res;
    }
};
