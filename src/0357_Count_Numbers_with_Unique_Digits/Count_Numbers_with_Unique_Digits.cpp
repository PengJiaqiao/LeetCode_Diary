class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> unique(n + 1, 9);
        unique[0] = 1;
        for(int i = 1; i <= n && i <= 10; i++) {
            int count = i - 1, num = 9;
            while(count) {
                unique[i] *= num;
                num--;
                count--;
            }
            unique[i] += unique[i - 1];
        }
        return n > 10? unique[10] : unique[n];
    }
};
