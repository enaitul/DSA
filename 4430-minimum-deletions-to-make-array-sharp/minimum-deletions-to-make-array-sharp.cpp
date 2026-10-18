class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int last = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == last) {
                cnt++;
            } else {
                last = nums[i];
            }
        }

        return cnt;
    }
};