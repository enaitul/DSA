class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> dp(n,1);
        vector<int> parent(n, -1);
        int maxlen = 1;
        int lastindex = 0;

        for (int i = 0; i< n; i++){
            for (int j = 0; j< i; j++){
                if (nums[i] % nums[j] == 0){
                    if (dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
            if (dp[i] > maxlen){
                maxlen = dp[i];
                lastindex = i;
            }
        }
        vector<int> ans;
        while (lastindex != -1){
            ans.push_back(nums[lastindex]);
            lastindex = parent[lastindex];
        }
        reverse(ans.begin(), ans.end());
        return ans;


    }
};