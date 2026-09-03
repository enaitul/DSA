class Solution {
public:
    int solve (int index, int prev, vector<int>&nums, vector<vector<int>> &dp){
        int n = nums.size();
        if (index == n){
            return 0;
        }
        if (dp[index][prev+1]!= -1) return dp[index][prev+1];
        int len = 0 + solve (index + 1, prev, nums,dp);
        if (prev == -1 || nums[index] > nums[prev]){
            len = max (len,1 + solve (index + 1, index, nums,dp));
        }
        return dp[index][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, nums, dp);
    }
};