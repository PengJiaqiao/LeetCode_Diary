class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        vector<vector<string>> res;
        _partition(s, 0, tmp, res);
        return res;
    }
private:
     void _partition(string& s, int idx, vector<string>& tmp, vector<vector<string>>& res) {
        if(idx == s.size()) {
            res.push_back(tmp);
            return;
        }
        for(int i = idx + 1; i <= s.size(); i++) {
            string cur = s.substr(idx, i - idx);
            if(isPalindrome(cur)) {
                tmp.push_back(cur);
                 _partition(s, i, tmp, res);
                tmp.pop_back();
            }
        }
         return;
    }  
    bool isPalindrome(string& s) {
        if(s.size() == 1) return true;
        for(int i = 0, j = s.size() - 1; i <= j; i++, j--) {
            if(s[i] != s[j]) return false;
        }
        return true;
    }
};
