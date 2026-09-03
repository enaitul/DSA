class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = INT_MAX;
        int n = nums1.size();
        for (int i = 0; i< n; i++){
            mini = min(mini, nums1[i]);
        }
        if (mini % 2 == 1) return true;
        else{
            bool allEven = true;

            for (int x : nums1) {
                if (x % 2 != 0) {
                    allEven = false;
                    break;
                }
            }

            if (allEven)
                return true;
            else
                return false;
        }
    }
};