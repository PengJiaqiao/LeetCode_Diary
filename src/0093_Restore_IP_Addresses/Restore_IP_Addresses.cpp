class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        return restore(s, 3, 0);
    }
private:
    vector<string> restore(string& s, int last, int idx) {//last: how many parts left behind. idx: index of the begining element
        vector<string> res = {};
        if(last == 0) {
            if(s.size() - idx == 1 || (s[idx] != '0' && (s.size() - idx == 2 || (s.size() - idx == 3 && s.substr(idx, 3) <= "255")))) res.push_back(s.substr(idx, s.size() - idx));
            return res;
        }
        vector<string> post;
        int begin = max(idx, (int)s.size() - 3 * last - 1), end = min(idx + 3, (int)s.size());
        if(s[idx] == '0') end = idx + 1;
        for(int i = begin; i < end; i++) {//i is the right border of current part
            if((i - idx) == 2) {
                if(s.substr(idx, 3) > "255") break;
            }
            post = restore(s, last - 1, i + 1);
            if(post.size() != 0) {
                string tmp = s.substr(idx, i - idx + 1);
                for(string& post_ : post) res.push_back(tmp + "." + post_);
            }
        }
        return res;
    }
};
