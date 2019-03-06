class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> S, T;
        for(auto &p : s) {
            if(S.find(p) == S.end()) S[p] = 1;
            else S[p] += 1;
        }
        for(auto &p : t) {
            if(T.find(p) == T.end()) T[p] = 1;
            else T[p] += 1;
        }
        for(auto &p : s) {
            if(S[p] != T[p]) return false;
        }
        return true;
    }
};
