class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        if(letters.size() == 0) return {};
        if(target >= letters[letters.size() - 1]) return letters[0];
        int l = 0, r = letters.size() - 1, m;
        while(l <= r) {
            m = l + (r - l) / 2;
            if(letters[m] <= target) l = m + 1;
            else r = m - 1;
        }
        return letters[l];
    }
};
