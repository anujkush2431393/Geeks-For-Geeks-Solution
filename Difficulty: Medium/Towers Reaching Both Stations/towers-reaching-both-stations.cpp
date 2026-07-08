class Solution {
  public:
    int countCoordinates(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        queue<pair<int, int>> q;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        // BFS for Station P (Top row + Left column)
        for (int i = 0; i < n; i++) {
            pacific[i][0] = true;
            q.push({i, 0});
        }
        for (int j = 1; j < m; j++) {
            pacific[0][j] = true;
            q.push({0, j});
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    !pacific[nx][ny] &&
                    mat[nx][ny] >= mat[x][y]) {
                    pacific[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        // BFS for Station Q (Bottom row + Right column)
        for (int i = 0; i < n; i++) {
            atlantic[i][m - 1] = true;
            q.push({i, m - 1});
        }
        for (int j = 0; j < m - 1; j++) {
            atlantic[n - 1][j] = true;
            q.push({n - 1, j});
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    !atlantic[nx][ny] &&
                    mat[nx][ny] >= mat[x][y]) {
                    atlantic[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans++;
            }
        }

        return ans;
    }
};