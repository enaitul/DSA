class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count (n, 1);
        int maxlen = 0;
        for(int i = 0; i< n; i++){
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j]){
                    if (dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if(dp[i] == dp[j] + 1) {
                        count[i] += count[j];
                    }
                }
            }
            maxlen = max(maxlen, dp[i]);
        }
        int ans = 0;
        for (int i =0; i<n; i++){
            if (dp[i] == maxlen){
                ans += count[i];
            }
        }
        return ans;
    }
};