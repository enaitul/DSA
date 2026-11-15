class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int V, int src) {
         vector<int> dist(V+1, 1e8);//1-based indexing
        dist[src] = 0;

        // Relax all edges V-1 times
        for (int i = 0; i < V - 1; i++) {

            for (auto &edge : edges) {

                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

                 int ans = 0;

        for (int i = 1; i <= V; i++) {

            if (dist[i] == 1e8) {
                return -1;
            }

            ans = max(ans, dist[i]);
        }

        return ans;
    } 
        

        
    
};