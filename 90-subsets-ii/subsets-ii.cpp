class Solution {
public:
    set<vector<int>> ans;

    void solve(int index, vector<int> curr, vector<int>& nums){
        if (index == nums.size()){
            ans.insert(curr);
            return;
        }

        curr.push_back(nums[index]);
        solve(index + 1, curr, nums);

        curr.pop_back();

        solve(index + 1, curr, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> curr;

        solve(0, curr, nums);

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};