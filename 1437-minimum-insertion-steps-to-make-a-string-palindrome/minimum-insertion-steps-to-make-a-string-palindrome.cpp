class Solution {
public:
    int longestCommonSubsequence(const string& text1, const string& text2) {
        int n = text1.length();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }

        return prev[n];
    }

    int minInsertions(string s) {
        int n = s.length();

        // 1. Create reversed string
        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());

        // 2. Find Length of Longest Palindromic Subsequence (LPS)
        int lpsLength = longestCommonSubsequence(s, s_rev);

        return n - lpsLength;
    }
};