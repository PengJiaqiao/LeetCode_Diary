class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        return dfs(digits, 0);
    }
private:
    vector<string> dfs(string& digits, int idx) {
        vector<string> cur = {};
        switch(digits[idx]) {
            case '1': cur = {"*"};
                break;
            case '2': cur = {"a", "b", "c"};
                break;
            case '3': cur = {"d", "e", "f"};
                break;
            case '4': cur = {"g", "h", "i"};
                break;
            case '5': cur = {"j", "k", "l"};
                break;
            case '6': cur = {"m", "n", "o"};
                break;
            case '7': cur = {"p", "q", "r", "s"};
                break;
            case '8': cur = {"t", "u", "v"};
                break;
            case '9': cur = {"w", "x", "y", "z"};
                break;
        }
        if(idx == digits.size() - 1) return cur;
        else {
            vector<string> res, post = dfs(digits, idx + 1);
            for(string cur_ : cur) {
                for(string post_ : post) res.push_back(cur_ + post_);
            }
            return res;
        }
    }
};
