class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        string res = {};
        for(string word : d) {
            int i = 0;
            for(char letter : word) {
                while(i < s.size() && s[i] != letter) i++;
                i++;
                if(i > s.size()) break;
            }
            if(i <= s.size()) {
                if(word.size() > res.size()) res = word;
                else if(word.size() == res.size()) res = word < res ? word : res;
            }
        }
        return res;
    }
};
