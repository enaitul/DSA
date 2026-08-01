class Solution {
public:
 void solve(int n, string curr, vector<string> &ans) {

        if (curr.length() == n) {
            ans.push_back(curr);
            return;
        }

        // Always place 0
        solve(n, curr + '1', ans);

        // Place 1 only if previous is not 1
        if (curr.empty() || curr.back() != '0') {
            solve(n, curr + '0', ans);
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        solve (n, "", ans);
        return ans;
    }
};