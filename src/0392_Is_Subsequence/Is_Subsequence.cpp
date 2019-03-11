class Solution {
public:
    bool isSubsequence(string s, string t) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int i = 0, j = 0;
        while(i < s.size() && j < t.size()) {
            if(s[i] == t[j]) {
                i++;
                j++;
            }
            else j++;
        }
        return i == s.size();
    }
};
