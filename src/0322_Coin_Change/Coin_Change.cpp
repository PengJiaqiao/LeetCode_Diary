class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> res(amount + 1, -1);
        res[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(int coin : coins) {
                if(coin > i) continue;
                if(res[i - coin] != -1) {
                    if(res[i] == -1) res[i] = res[i - coin] + 1;
                    else res[i] = min(res[i], res[i - coin] + 1);
                }
            }
        }
        return res[amount];
    }
};
