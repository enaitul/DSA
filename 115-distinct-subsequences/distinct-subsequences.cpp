class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        // Use double to safely avoid integer overflow on large test cases
        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

        // Base case: An empty target string t (j = 0) can be formed in 1 way from any prefix of s
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    // Option 1: Match s[i-1] with t[j-1] -> dp[i-1][j-1]
                    // Option 2: Skip s[i-1]              -> dp[i-1][j]
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    // Characters don't match, we must skip s[i-1]
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return (int)dp[n][m];
    }
};