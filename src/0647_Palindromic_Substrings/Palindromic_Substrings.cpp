class Solution {
public:
    int countSubstrings(string s) {
	    ios::sync_with_stdio(false);
        cin.tie(0);
        if(s.size() == 0) return 0;
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            count += countstrings(s, i, i);//odd
            count += countstrings(s, i, i + 1);//even
        }
        return count + s.size();
    }
private:
    int countstrings(const string& s, int l, int r) {
        int count = 0;
        if(l != r) {
            if(s[l] == s[r]) count = 1;
            else return 0;
        }
        while(l > 0 && r < s.size() - 1) {
            l--;
            r++;
            if(s[l] == s[r]) count++;
            else break;
        }
        return count;
    }
};
