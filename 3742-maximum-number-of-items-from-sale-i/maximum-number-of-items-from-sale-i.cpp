class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        // Step 1: Calculate free-item bonus for each item
        vector<int> bonus(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    bonus[i]++;
                }
            }
        }

        // Step 2: DP initialization
        vector<int> dp(budget + 1, 0);

        // Step 3: Process each item type
        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            int extra = bonus[i];

            vector<int> cur = dp;

            for (int b = price; b <= budget; b++) {

                // Buy first copy: get the bonus only once
                cur[b] = max(cur[b],
                             dp[b - price] + 1 + extra);

                // Buy additional copies: no bonus
                cur[b] = max(cur[b],
                             cur[b - price] + 1);
            }

            dp = cur;
        }

        return dp[budget];
    }
};