class DSU {
  public:
    vector<int> parent, size;
    
    DSU(int n){
        parent.resize(n);
        size.resize(n, 1);
        
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    
    int find (int nd){
        if (parent[nd] == nd){
            return nd;
        }
        return parent[nd] = find(parent[nd]);
    }
    
    void unite(int u, int v){
        u = find(u);
        v = find(v);
        
        if (u == v) return;
        
        if (size[u] < size[v]){
            parent[u] = v;
            size[v] += size[u];
        }
        else{
            parent[v] = u;
            size[u] += size[v];
        }
        
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu (n*n);

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        //collect all land
        for (int row = 0; row < n; row++){
            for (int col = 0; col < n; col++){
                if (grid[row][col] == 0){
                    continue;
                }

                int node = row * n + col;

                for (int i = 0; i < 4; i++){
                    int nr = row + dr[i];
                    int nc = col + dc[i];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        int adjnode = nr * n + nc;

                        dsu.unite(node, adjnode);
                    }
                }
            }
        }

        //take a water, turn it into land, find max island size
        int ans = 0;
        for (int row = 0; row < n; row ++){
            for (int col = 0; col < n; col++){
                if (grid[row][col] == 1) continue;

                unordered_set<int> st;

                for (int i = 0; i < 4; i++){
                    int nr = row + dr[i];
                    int nc = col + dc[i];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        int adjnode = nr * n + nc;

                        st.insert(dsu.find(adjnode));
                    }
                }
                int area = 1;

                for (int root : st){
                    area += dsu.size[root];
                }

                ans = max(ans, area);
            }
        }
        if (ans == 0){
            return n * n;
        }
        return ans;
    }
};