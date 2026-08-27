class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        // Base Cases (NO dp[i][j] indexing here!)
        if (i < 0 && j < 0) return true;
        if (j < 0 && i >= 0) return false;
        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
        }
        if (p[j] == '*') {
            // '*' matches empty sequence (j - 1) OR matches 1+ characters (i - 1)
            return dp[i][j] = solve(i, j - 1, s, p, dp) || solve(i - 1, j, s, p, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        
        if (m == 0 && n == 0) return true;

        // DP table sized m x n; handle empty edge cases cleanly
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(m - 1, n - 1, s, p, dp);
    }
};