class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        if(prices.size() == 0) return 0;
        int profit = 0, Min = prices[0];
        for(int price : prices) {
            profit = max(profit, price - Min);
            Min = min(Min, price);
        }
        return profit;
    }
};
