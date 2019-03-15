class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        if(prices.size() <= 1) return 0;
        vector<int> buy(prices.size()), sell(prices.size());
        buy[0] = -prices[0];
        sell[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            buy[i] = max(buy[i - 1], (i > 1 ? sell[i - 2] : 0) - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }
        return *(sell.rbegin());
    }
};
