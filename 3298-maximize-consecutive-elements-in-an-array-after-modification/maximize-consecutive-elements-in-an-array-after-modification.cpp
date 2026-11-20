class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        unordered_map<int, int> dp;

        int ans = 0;

        for (int x : nums) {

            //Increase x to x + 1
            dp[x + 1] = max(dp[x + 1], dp[x] + 1);

            //Keep x unchanged
            dp[x] = max(dp[x], dp[x - 1] + 1);

            ans = max({ans, dp[x], dp[x + 1]});
        }

        return ans;
    }
};