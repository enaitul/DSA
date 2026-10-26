class Solution {
private:
    void dfs(int r, int c, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& visited, long long& currentSum) {
        visited[r][c] = true;
        currentSum += grid[r][c];

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && grid[nr][nc] > 0) {
                dfs(nr, nc, m, n, grid, visited, currentSum);
            }
        }
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int validIslandsCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If we find an unvisited cell with land (positive integer)
                if (grid[i][j] > 0 && !visited[i][j]) {
                    long long currentSum = 0;
                    dfs(i, j, m, n, grid, visited, currentSum);

                    // Check if the total value of this island is divisible by k
                    if (currentSum % k == 0) {
                        validIslandsCount++;
                    }
                }
            }
        }

        return validIslandsCount;
    }
};