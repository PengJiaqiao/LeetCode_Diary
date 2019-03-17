class Solution {
public:
    int countPrimes(int n) {
        if(n < 2) return 0;
        vector<bool> notPrimes(n + 1, true);
        int count = 0;
        for(int i = 2; i < n; i++) {
            if(notPrimes[i]) {
                count++;
                for(int j = 2; i * j < n; j++) notPrimes[i * j] = false;
            }
        }
        return count;
    }
};
