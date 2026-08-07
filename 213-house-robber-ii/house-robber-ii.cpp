class Solution {
public:
    int solve (int index, int start, vector<int>& nums, vector<int> &dp){
        if (index < start) return 0;
        if (index == start) return nums[start];
        if (dp[index] != -1) return dp[index];

        int rob = nums[index] + solve (index - 2, start, nums, dp);
        int skip = solve (index - 1,start, nums, dp);

        return dp[index] = max(rob, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        vector<int> dp1(n, -1);
        int case1 = solve(n-2, 0, nums, dp1);

        vector<int> dp2(n, -1);
        int case2 = solve(n-1, 1, nums, dp2);
        return max(case1, case2);
    }
};