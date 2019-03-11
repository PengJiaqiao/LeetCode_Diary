class Solution {
public:
    int numSquares(int n) {
        if(n < 4) return n;
        int *dp = new int[n + 1];
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            int min = n;
            for(int j = 1; j <= int(sqrt(i)); j++){
                min = (min < dp[i - j * j] + 1)? min : dp[i - j * j] + 1;
                if(j * j == i) min = 1;
            }
            dp[i] = min;
        }
        return dp[n];
    }
};
