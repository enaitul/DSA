
class Solution {
public:
    int countConsistent(vector<int>& nums) {

        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            int mn = nums[i];
            int bitwiseAnd = nums[i];

            for (int j = i; j < n; j++) {

                mn = min(mn, nums[j]);

                bitwiseAnd &= nums[j];

                if (mn == bitwiseAnd) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
