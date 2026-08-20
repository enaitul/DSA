class Solution {
public:
    int solve (int index, int currentsum, int target, vector<int>&coins, vector<vector<int>>&dp){
        if (index == coins.size()) {
            return currentsum == target? 1: 0; 
        }

        if (dp[index][currentsum] != -1) return dp[index][currentsum];

        //nottake
        int nottake = solve (index + 1, currentsum, target, coins, dp);
        int take = 0;
        if (currentsum + coins[index] <= target){
            take = solve (index , currentsum + coins[index], target, coins, dp);
        }
        return dp[index][currentsum] = nottake + take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp( n + 1, vector<int> ( amount + 1, -1));
        return solve (0,0, amount, coins, dp);
    }
};