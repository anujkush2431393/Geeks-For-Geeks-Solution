class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Mark unsafe cells
        vector<vector<int>> unsafe(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    unsafe[i][j] = 1;

                    for (int k = 0; k < 4; k++) {
                        int ni = i + dr[k];
                        int nj = j + dc[k];

                        if (ni >= 0 && ni < n && nj >= 0 && nj < m)
                            unsafe[ni][nj] = 1;
                    }
                }
            }
        }

        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));

        // Start from every safe cell in first column
        for (int i = 0; i < n; i++) {
            if (!unsafe[i][0]) {
                dist[i][0] = 1;   // Starting cell counts as 1 step
                q.push({i, 0});
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            // Reached last column
            if (c == m - 1)
                return dist[r][c];

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    !unsafe[nr][nc] &&
                    dist[nr][nc] == -1) {

                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return -1;
    }
};