class Solution {
public:

    int solve(int ind, int buy, int cap, vector<int>& prices,
              vector<vector<vector<int>>>& dp) {

        // No days left OR no transactions left
        if (ind == prices.size() || cap == 0)
            return 0;

        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];

        if (buy) {

            dp[ind][buy][cap] = max(
                -prices[ind] + solve(ind + 1, 0, cap, prices, dp),
                solve(ind + 1, 1, cap, prices, dp)
            );

        }
        else {

            dp[ind][buy][cap] = max(
                prices[ind] + solve(ind + 1, 1, cap - 1, prices, dp),
                solve(ind + 1, 0, cap, prices, dp)
            );
        }

        return dp[ind][buy][cap];
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(2, vector<int>(3, -1))
        );

        return solve(0, 1, 2, prices, dp);
    }
};