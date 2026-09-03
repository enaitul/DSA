class Solution {
public:

    int solve(int ind, int buy, vector<int>& prices, int fee,
              vector<vector<int>>& dp) {

        // No days left
        if (ind == prices.size())
            return 0;

        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        if (buy) {

            // Buy OR skip
            dp[ind][buy] = max(
                -prices[ind] + solve(ind + 1, 0, prices, fee, dp),
                solve(ind + 1, 1, prices, fee, dp)
            );

        }
        else {

            // Sell (pay fee) OR hold
            dp[ind][buy] = max(
                prices[ind] - fee + solve(ind + 1, 1, prices, fee, dp),
                solve(ind + 1, 0, prices, fee, dp)
            );
        }

        return dp[ind][buy];
    }

    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        vector<vector<int>> dp(
            n,
            vector<int>(2, -1)
        );

        return solve(0, 1, prices, fee, dp);
    }
};