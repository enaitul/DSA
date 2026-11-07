class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        
        // Min-heap for available servers: stores {weight, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> available;
        
        // Min-heap for unavailable (busy) servers: stores {free_time, {weight, index}}
        priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> unavailable;
        
        // Initially, all servers are available
        for (int i = 0; i < n; ++i) {
            available.push({servers[i], i});
        }
        
        vector<int> ans(m);
        long long curr_time = 0;
        
        for (int j = 0; j < m; ++j) {
            curr_time = max(curr_time, (long long)j);
            
            // If no servers are available, fast-forward time to the next available server
            if (available.empty() && unavailable.top().first > curr_time) {
                curr_time = unavailable.top().first;
            }
            
            // Free up servers that have completed their tasks by the current time
            while (!unavailable.empty() && unavailable.top().first <= curr_time) {
                auto top_server = unavailable.top().second;
                unavailable.pop();
                available.push(top_server);
            }
            
            // Assign the current task (j) to the best available server
            auto [weight, idx] = available.top();
            available.pop();
            
            ans[j] = idx;
            unavailable.push({curr_time + tasks[j], {weight, idx}});
        }
        
        return ans;
    }
};