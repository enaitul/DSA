class Solution {
public:
   int solve(int i, int j, const string& text1, const string& text2, vector<vector<int>>& dp) {
        // Base Case: empty string prefix
        if (i < 0 || j < 0) return 0;

        // Return cached result if already computed
        if (dp[i][j] != -1) return dp[i][j];

        // Choice 1: Characters match
        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + solve(i - 1, j - 1, text1, text2, dp);
        }

        // Choice 2: Characters mismatch
        int skipText1 = solve(i - 1, j, text1, text2, dp);
        int skipText2 = solve(i, j - 1, text1, text2, dp);

        return dp[i][j] = max(skipText1, skipText2);
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        // dp[i][j] stores the result for text1[0...i] and text2[0...j]
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, text1, text2, dp);
    }

};