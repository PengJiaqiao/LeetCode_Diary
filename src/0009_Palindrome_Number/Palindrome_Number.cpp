class Solution {
public:
    bool isPalindrome(int x) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        if(x == 0) return true;
        if(x < 0 || x % 10 == 0) return false;
        int l = x;//read x from l
        int r = 0;//read x from r
        while(l > r) {
            r = r * 10 + l % 10;
            l = l / 10;
        }
        if(l == r || r / 10 == l) return true;
        else return false;
    }
};
