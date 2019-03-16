class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        if(prices.empty()) return 0;
        if(k == 0) return 0;
        if(k >= prices.size() / 2) {
            int profit = 0, pre = prices[0];
            for(int i = 1; i < prices.size(); i++) {
                if(prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
            }
            return profit;
        }
        vector<int> buy(k, -prices[0]), sell(k, 0);
        for(int i = 1; i < prices.size(); i++) {
            buy[0] = max(buy[0], - prices[i]);
            sell[0] = max(sell[0], buy[0] + prices[i]);
            for(int j = 1; j < k; j++) {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return *(sell.rbegin());
    }
};
