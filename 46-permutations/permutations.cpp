class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& current,
                   vector<vector<int>>& result, vector<bool>& used) {

        // A complete permutation has been formed
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        // Try every number at the current position
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;  // Don't reuse a number

            used[i] = true;
            current.push_back(nums[i]);

            backtrack(nums, current, result, used);

            // Undo the choice to explore another possibility
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        backtrack(nums, current, result, used);
        return result;
    }
};