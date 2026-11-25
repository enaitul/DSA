
class Solution {
public:
    using ll = long long;

    const ll MOD1 = 1000000007;
    const ll MOD2 = 1000000009;
    const ll BASE = 911382323;

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<ll> h1(n + 1, 0), h2(n + 1, 0);
        vector<ll> p1(n + 1, 1), p2(n + 1, 1);
        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * BASE + nums[i] + 1) % MOD1;
            h2[i + 1] = (h2[i] * BASE + nums[i] + 1) % MOD2;

            p1[i + 1] = (p1[i] * BASE) % MOD1;
            p2[i + 1] = (p2[i] * BASE) % MOD2;
        }

        // Check whether a unique subarray exists
        auto check = [&](int len) -> bool {
            map<pair<ll, ll>, int> freq;

            for (int i = 0; i + len <= n; i++) {
                int j = i + len;

                ll x = (h1[j] - h1[i] * p1[len] % MOD1 + MOD1) % MOD1;
                ll y = (h2[j] - h2[i] * p2[len] % MOD2 + MOD2) % MOD2;

                freq[{x, y}]++;
            }

            for (auto& [hash, count] : freq) {
                if (count == 1)
                    return true;
            }

            return false;
        };

        // Binary Search for minimum valid length
        int low = 1, high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
