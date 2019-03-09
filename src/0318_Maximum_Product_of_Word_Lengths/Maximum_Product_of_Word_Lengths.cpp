class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.size() == 0) return 0;
        vector<int> v;
        for(string word : words) {
            int res = 0;
            for(char letter : word) {
                res |= 1 << (letter - 'a');
            }
            v.push_back(res);
        }
        int Max = 0;
        for(int i = 0; i < words.size() - 1; i++) {
            for(int j = i + 1; j < words.size(); j++) {
                if((v[i] & v[j]) == 0) Max = max(Max, (int)words[i].size() * (int)words[j].size());
            }
        }
        return Max;
    }
};
