class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());

        int n = s.length();

        // Standard 2D LCS Table on s and s_rev
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                
                // Characters match -> extend length
                if (s[i - 1] == s_rev[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } 
                // Characters mismatch -> take best option
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][n];
    }
};