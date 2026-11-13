
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        long long ans = 0;
        long long cost = 0;

        deque<int> dq;

        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {

            // Merge smaller groups into the current element.
            while (!dq.empty() && nums[dq.back()] < nums[i]) {

                int l = dq.back();
                dq.pop_back();

                int r = dq.empty() ? j + 1 : dq.back();

                cost += 1LL * (r - l) * (nums[i] - nums[l]);
            }

            // Insert current index.
            dq.push_back(i);

            // Shrink the window while cost exceeds k.
            while (cost > k) {

                cost -= nums[dq.front()] - nums[j];

                if (dq.front() == j) {
                    dq.pop_front();
                }

                j--;
            }

            // Count all valid subarrays starting at i.
            ans += j - i + 1;
        }

        return ans;
    }
};
