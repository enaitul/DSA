class Solution {
public:
    typedef pair<long long, long long> P;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<P> adj[n];
        for (auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        //pq
        priority_queue<P, vector<P>, greater<P>> pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        long long mod = 1e9 + 7;

        pq.push({0, 0});

        while (!pq.empty()){
            auto it =pq.top();
            pq.pop();
            long long cost = it.first;
            long long node = it.second;

            for (auto iter: adj[node]){
                long long adjnode = iter.first;
                long long edw = iter.second;
                
                //if we are arriving at the first time
                if (edw + cost < dist[adjnode]){
                    dist[adjnode] = edw + cost;
                    pq.push({edw + cost, adjnode});
                    ways[adjnode] = ways[node];
                }

                else if (edw + cost == dist[adjnode]){
                    ways[adjnode] += ways[node];
                    ways[adjnode] %= mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};