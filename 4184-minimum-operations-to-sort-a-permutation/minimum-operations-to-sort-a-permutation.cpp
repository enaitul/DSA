
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int p = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) break;
            if (i == n - 1) return 0;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                p = i;
                break;
            }
        }

        bool inc = true, dec = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (nums[0] + i) % n)
                inc = false;

            if (nums[i] != (nums[0] - i + n) % n)
                dec = false;
        }

        if (inc)
            return min(p, n - p + 2);

        if (dec)
            return min(n - p, 1 + (p + 1) % n);

        return -1;
    }
};
