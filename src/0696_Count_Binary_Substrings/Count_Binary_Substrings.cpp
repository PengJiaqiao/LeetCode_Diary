class Solution {
public:
    int countBinarySubstrings(string s) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        if(s.size() == 0) return 0;
        int count = 0;
        for(int i = 0; i < s.size() - 1; i++) {
            count += countstrings(s, i, i + 1);
        }
        return count;
    }
private:
    int countstrings(const string& s, int l, int r) {
        int count = 0;
        if(s[l] != s[r]) count = 1;
        else return count;
        while(l > 0 && r < s.size() - 1) {
            l--;
            r++;
            if(s[l] != s[l + 1] || s[r] != s[r - 1]) break;
            else count++;
        }
        return count;
    }
};
