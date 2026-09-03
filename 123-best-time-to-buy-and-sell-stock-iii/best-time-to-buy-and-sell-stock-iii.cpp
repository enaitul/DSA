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

        
       vector<vector<int>>next(2, vector<int> (3, 0));
       vector<vector<int>>curr(2, vector<int> (3, 0));


        for (int ind = n-1; ind>= 0; ind--){
            for (int buy = 0; buy <=1; buy++){
                for (int cap = 1; cap <= 2; cap++){
                     if (buy == 1) {
           
                     curr[buy][cap] = max(
                -prices[ind] + next[0][cap] ,
                next[1][cap]
            );
        }
        else {
            
            curr[buy][cap] = max(
                prices[ind] + next[1][cap - 1],
                next[0][cap]
            );
        }
                }
            }
            next = curr;
        }

        return next[1][2];
    }
};