class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        if (n == 1) return 1;
        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        queue <tuple<int, int, int>> q;
        q. push({0, 0, 1});
        grid[0][0] = 1; //visited

        while (!q.empty()){
            auto [r, c, dist] = q.front();
            q.pop();
            for (auto &dir: directions){
                int nr = r + dir.first;
                int nc = c + dir.second;
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] ==0){
                    if (nr == n-1 && nc == n-1){
                        return dist + 1;

                    }
                    q.push({nr, nc, dist + 1});
                    grid [nr][nc] = 1; //visited
                }
            }
        }
        return -1;
    }
};