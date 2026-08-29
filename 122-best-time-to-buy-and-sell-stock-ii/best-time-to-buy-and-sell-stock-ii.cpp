class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            // If today's price is higher than yesterday's, take the profit
            if (prices[i] > prices[i - 1]) {
                max_profit += prices[i] - prices[i - 1];
            }
        }
        
        return max_profit;
    }
};