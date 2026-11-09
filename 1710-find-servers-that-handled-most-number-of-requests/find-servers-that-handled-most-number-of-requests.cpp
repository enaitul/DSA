
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busy;

        vector<int> cnt(k, 0);

        for (int i = 0; i < arrival.size(); i++) {

            // Free all servers whose requests have finished
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                int s = busy.top().second;
                busy.pop();

                available.insert(s);
            }

            // All servers are busy
            if (available.empty()) {
                continue;
            }

            int start = i % k;

            // Find the next available server
            auto it = available.lower_bound(start);

            // Wrap around if necessary
            if (it == available.end()) {
                it = available.begin();
            }

            int s = *it;

            // Assign the request
            available.erase(it);

            long long finish = (long long)arrival[i] + load[i];

            busy.push({finish, s});

            cnt[s]++;
        }

        // Find maximum number of handled requests
        int mx = *max_element(cnt.begin(), cnt.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (cnt[i] == mx) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
