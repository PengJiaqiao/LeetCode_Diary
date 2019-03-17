class Solution {
public:
    string convertToTitle(int n) {
        if (n == 0) return "";
        n--;
        return convertToTitle(n / 26) + (char)(n % 26 + 'A');
    }
};
