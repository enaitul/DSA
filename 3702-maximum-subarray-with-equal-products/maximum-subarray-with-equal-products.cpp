
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            long long product = 1;
            int gcdVal = 0;
            int lcmVal = 1;

            for (int j = i; j < n; j++) {

                int x = nums[j];

                product *= x;

                if (product > 25200)
                    break;

                gcdVal = gcd(gcdVal, x);
                lcmVal = lcm(lcmVal, x);

                if (product == 1LL * gcdVal * lcmVal) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
