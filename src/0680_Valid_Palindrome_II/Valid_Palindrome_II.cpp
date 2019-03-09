class Solution {
public:
    bool flag = false;
    bool validPalindrome(string s) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int i = 0, j = s.size() - 1;
        while(i < j){
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                if(flag) return false;
                flag = true;
                return validPalindrome(s.substr(i, j - i)) || validPalindrome(s.substr(i + 1, j - i));
            }
        }
        return true;
    }
};
