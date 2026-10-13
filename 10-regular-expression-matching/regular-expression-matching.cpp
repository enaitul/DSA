class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        //dp[i][j] = s er prothom i character, p er prothom j characters ke match kore?
        //if yes, tahole true, nahole false
        // amra n + 1 rows and m + 1 columns use korbo karon idx 0 ta empty string ba pattern ke represent korbe, initially prottek ta state false thakbe 
        //Ei Lucky tui ki amar comment porchis?

        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        //Base case ta hobe je empry string, empty pattern ke match krche
        dp[0][0] = true;
        //s = "" p = "a*b*", mane s khali, kintu p khali na
        for (int j = 2; j<=m; j++){
            if(p[j-1] == '*'){
                dp[0][j] = dp[0][j-2];
            }
        }
        for (int i = 1; i<=n; i++){
            for (int j = 1; j<=m; j++){
                if (p[j-1] == '*'){
                    dp[i][j] = dp[i][j-2];

                    if(p[j-2] == '.' || p[j-2] == s[i-1]){
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                }

                else{
                    if(p[j-1] == '.' || p[j-1] == s[i-1]){
                        dp[i][j] = dp[i-1][j-1];
                        //current characters gulo match kore jacche, tai ans depends on ager character gulo match korche ki na
                    }
                }

            }
        }
        return dp[n][m];
    }
};