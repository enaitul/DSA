class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void solve(int start, vector<int>& nums) {

        ans.push_back(path);

        for (int i = start; i < nums.size(); i++) {

            if (i > start && nums[i] == nums[i - 1])
                continue;

            path.push_back(nums[i]);

            solve(i + 1, nums);

            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        solve(0, nums);

        return ans;
    }
};