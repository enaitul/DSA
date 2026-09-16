class Solution {
public:
    int numberOfSets(int n, int k) {

        const int MOD = 1e9 + 7;

        vector<vector<long long>> dp(
            n,
            vector<long long>(k + 1, 0)
        );

        // 0 segments = 1 way
        // We simply don't draw anything.
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int j = 1; j <= k; j++) {

            long long sum = 0;

            for (int i = 1; i < n; i++) {

                // dp[i-1][j-1] becomes available
                // as a possible starting point.
                sum = (sum + dp[i - 1][j - 1]) % MOD;

                // Don't end a segment at i
                // OR end a segment at i.
                dp[i][j] = (dp[i - 1][j] + sum) % MOD;
            }
        }

        return dp[n - 1][k];
    }
};