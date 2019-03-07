class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> M;
        for(auto& t : s) {
            if(M.find(t) == M.end()) M[t] = 1;
            else M[t] += 1;
        }
        int sum = s.size();
        for(auto& p : M) if(p.second % 2) sum--;
        return sum < s.size()? sum + 1 : sum;
    }
};
