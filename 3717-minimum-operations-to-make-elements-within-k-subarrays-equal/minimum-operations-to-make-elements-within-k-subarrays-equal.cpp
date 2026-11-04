
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<long long> low, high;
        long long sumLow = 0, sumHigh = 0;

        // Rebalance the two halves
        auto balance = [&]() {
            while (low.size() > high.size() + 1) {
                long long val = *low.rbegin();

                low.erase(prev(low.end()));
                sumLow -= val;

                high.insert(val);
                sumHigh += val;
            }

            while (low.size() < high.size()) {
                long long val = *high.begin();

                high.erase(high.begin());
                sumHigh -= val;

                low.insert(val);
                sumLow += val;
            }
        };

        // Insert an element
        auto add = [&](long long val) {
            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                sumLow += val;
            } else {
                high.insert(val);
                sumHigh += val;
            }

            balance();
        };

        // Remove an element
        auto remove = [&](long long val) {
            auto it = low.find(val);

            if (it != low.end()) {
                low.erase(it);
                sumLow -= val;
            } else {
                it = high.find(val);
                high.erase(it);
                sumHigh -= val;
            }

            balance();
        };

        // Calculate cost of current window
        auto getCost = [&]() -> long long {
            long long median = *low.rbegin();

            return median * low.size() - sumLow
                 + sumHigh - median * high.size();
        };

        // Calculate cost of every window of size x
        vector<long long> cost(n - x + 1);

        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost[0] = getCost();

        for (int i = 1; i <= n - x; i++) {
            remove(nums[i - 1]);
            add(nums[i + x - 1]);

            cost[i] = getCost();
        }

        // DP
        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {

                // Skip current element
                dp[i][j] = dp[i - 1][j];

                // Select a window ending at i - 1
                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
