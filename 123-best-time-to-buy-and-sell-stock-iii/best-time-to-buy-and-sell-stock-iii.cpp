class Solution {
public:

    // int solve(int ind, int buy, int cap, vector<int>& prices,
    //           vector<vector<vector<int>>>& dp) {

    //     // No days left OR no transactions left
    //     if (ind == prices.size() || cap == 0)
    //         return 0;

    //     if (dp[ind][buy][cap] != -1)
    //         return dp[ind][buy][cap];

    //     int profit = 0;

    //     if (buy) {
           
    //         profit = max(
    //             -prices[ind] + solve(ind + 1, 0, cap, prices, dp),
    //             solve(ind + 1, 1, cap, prices, dp)
    //         );
    //     }
    //     else {
            
    //         profit = max(
    //             prices[ind] + solve(ind + 1, 1, cap - 1, prices, dp),
    //             solve(ind + 1, 0, cap, prices, dp)
    //         );
    //     }

    //     return dp[ind][buy][cap] = profit;
    // }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        // [day][buy/sell][transactions remaining]
        vector<vector<vector<int>>> dp(
            n+1,
            vector<vector<int>>(2, vector<int>(3, 0))
        );
        

        for (int ind = n-1; ind>= 0; ind--){
            for (int buy = 0; buy <=1; buy++){
                for (int cap = 1; cap <= 2; cap++){
                     if (buy == 1) {
           
                     dp[ind][buy][cap] = max(
                -prices[ind] + dp[ind + 1][0][cap] ,
                dp[ind + 1][1][cap]
            );
        }
        else {
            
            dp[ind][buy][cap] = max(
                prices[ind] + dp[ind + 1][1][cap - 1],
                dp[ind + 1][0][cap]
            );
        }
                }
            }
        }

        return dp[0][1][2];
    }
};