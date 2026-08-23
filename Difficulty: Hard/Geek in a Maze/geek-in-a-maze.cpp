class Solution {
  public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Starting cell is blocked
        if (mat[r][c] == '#')
            return 0;

        const int INF = 1e9;

        // dist[i][j] = minimum number of UP moves needed
        // to reach (i,j)
        vector<vector<int>> dist(n, vector<int>(m, INF));

        deque<pair<int, int>> dq;

        dist[r][c] = 0;
        dq.push_front({r, c});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                if (mat[nx][ny] == '#')
                    continue;

                // Moving UP costs 1, all other moves cost 0
                int cost = (nx < x) ? 1 : 0;

                if (dist[x][y] + cost < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + cost;

                    if (cost == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] == '#')
                    continue;

                // Minimum upward moves required
                int upMoves = dist[i][j];

                if (upMoves > u)
                    continue;

                // From:
                // row difference = downMoves - upMoves
                //
                // i - r = downMoves - upMoves
                // downMoves = upMoves + i - r
                int downMoves = upMoves + (i - r);

                if (downMoves <= d)
                    ans++;
            }
        }

        return ans;
    }
};