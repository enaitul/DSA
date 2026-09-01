class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        // Give every litter cell an index
        vector<vector<int>> id(m, vector<int>(n, -1));

        int sr = 0, sc = 0;
        int litterCount = 0;

        // Find S and number/index of L
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }

        // No litter
        if (litterCount == 0)
            return 0;

        int totalMasks = 1 << litterCount;

        /*
            visited[r][c][energy][mask]

            true = this state has already been visited
        */
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(totalMasks, false)
                )
            )
        );

        // State:
        // row, col, remaining energy, collected litter mask
        queue<tuple<int, int, int, int>> q;

        // Initially no litter is collected
        int startMask = 0;

        q.push({sr, sc, energy, startMask});
        visited[sr][sc][energy][startMask] = true;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int sz = q.size();

            // Process one BFS level
            while (sz--) {

                auto [r, c, currEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == totalMasks - 1) {
                    return moves;
                }

                // If energy is 0, we cannot move anymore.
                // This is okay only if we are standing on R,
                // but R would already have restored our energy.
                if (currEnergy == 0)
                    continue;

                // Try four directions
                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    // Obstacle
                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Moving costs 1 energy
                    int newEnergy = currEnergy - 1;

                    // Reset area
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    // Update litter mask
                    int newMask = mask;

                    if (classroom[nr][nc] == 'L') {

                        int litterIndex = id[nr][nc];

                        // Mark this litter as collected
                        newMask |= (1 << litterIndex);
                    }

                    // If this state hasn't been visited
                    if (!visited[nr][nc][newEnergy][newMask]) {

                        visited[nr][nc][newEnergy][newMask] = true;

                        q.push({
                            nr,
                            nc,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};