class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // make a set
        //push every element to the set
        //if nums and set size are same true
        //else false

        unordered_set<int> s;
        for (int i = 0; i< nums.size(); i++){
            s.insert(nums[i]);
        }
        if (s.size() == nums.size()) return false;
        else return true;
    }
};