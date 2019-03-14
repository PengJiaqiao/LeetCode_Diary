class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1;
        if(coins.size() == 0) return 0;
        vector<int> res(amount + 1);
        res[0] = 1;
        for(int coin : coins) {
            for(int i = coin; i <= amount; i++) {
                res[i] += res[i - coin];
            }
        }
        return res[amount];
    }
};
