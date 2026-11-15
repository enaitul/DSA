class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> dist(n, vector<int>(n, 1e8));

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != 1e8 && dist[k][j] != 1e8) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        vector<int> count(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    count[i]++;
                }
            }
        }

        int ans = -1;
        int minCount = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (count[i] <= minCount) {
                minCount = count[i];
                ans = i;
            }
        }
        return ans;
    }
};