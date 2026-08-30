class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_set<int> visited;
        unordered_set<int> invalid;

        int n = nums.size();

        visited.insert(nums[0]);
        for (int i = 1; i< n; i++){
            if (nums[i] != nums[i-1]){
                if (visited.count(nums[i]) != 0){
                    invalid.insert(nums[i]);
                }
                visited.insert(nums[i]);
            }
        }
        return visited.size() - invalid.size();
    }
};