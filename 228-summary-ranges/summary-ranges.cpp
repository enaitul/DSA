class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        vector<string> ans;

        int n = nums.size();
        int i = 0;

        while (i < n) {

            // Start of current range
            int start = nums[i];

            int j = i;

            // Find the end of consecutive sequence
            while (j + 1 < n &&
                   (long long)nums[j + 1] == (long long)nums[j] + 1) {
                j++;
            }

            // End of current range
            int end = nums[j];

            // Convert range into string
            if (start == end) {
                ans.push_back(to_string(start));
            }
            else {
                ans.push_back(to_string(start) + "->" + to_string(end));
            }

            // Move to next range
            i = j + 1;
        }

        return ans;
    }
};