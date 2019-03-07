class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> S, T;
        for(int i = 0; i < s.size(); i++) {
            if(S.find(s[i]) == S.end() && T.find(t[i]) == T.end()) {
                S[s[i]] = i;
                T[t[i]] = i;
            }
            else if(S.find(s[i]) != S.end() && T.find(t[i]) != T.end()) {
                if(S[s[i]] != T[t[i]]) return false;
            }
            else return false;
        }
        return true;
    }
};
