class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int j = i + 1;
        while (i < n && j < n) {
            if (nums[i] == nums[j]) {
                return nums[i];
            } 
            else {
                i = j + 1;
                if (nums[i] == nums[j]) {
                    return nums[i];
                }
                j = i + 1;
                if (nums[i] == nums[j]) {
                    return nums[j];
                }
            }
        }
        return -1;
    }
};