class Solution {
public:
    int solve (int index, int currentsum, int target, vector<int>&nums, vector<vector<int>>&dp){
        if (index == nums.size()){
            return currentsum == target? 1: 0;
        }
        if (dp[index][currentsum]!= -1) return dp[index][currentsum];

        int exclude = solve (index + 1, currentsum, target, nums, dp);
        int include = 0;
        if (currentsum + nums[index] <= target){
            include = solve (index + 1, currentsum + nums[index], target, nums, dp);
        }
        return dp[index][currentsum] = include + exclude;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalsum = 0;
        for (int num : nums){
            totalsum += num;
        }
        if (target > totalsum) return 0;
        if ((target + totalsum) % 2 != 0 || (target + totalsum)< 0) return 0;

        int targetsum = (target + totalsum)/2;
        vector<vector<int>> dp (n + 1, vector<int>( targetsum + 1, -1));

        return solve (0, 0, targetsum, nums, dp);
    }
};