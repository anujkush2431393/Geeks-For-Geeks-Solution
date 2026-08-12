class Solution {
public:
    vector<int> findWays(vector<vector<int>>& grid) {
        int n = grid.size();
        const int MOD = 1e9 + 7;

        vector<vector<long long>> ways(n, vector<long long>(n, 0));
        vector<vector<int>> best(n, vector<int>(n, 0));

        ways[0][0] = 1;
        best[0][0] = grid[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                // Move Down from the cell above
                if (i > 0 &&
                    (grid[i - 1][j] == 2 || grid[i - 1][j] == 3)) {

                    ways[i][j] =
                        (ways[i][j] + ways[i - 1][j]) % MOD;

                    if (ways[i - 1][j] > 0) {
                        best[i][j] = max(
                            best[i][j],
                            best[i - 1][j] + grid[i][j]
                        );
                    }
                }

                // Move Right from the cell on the left
                if (j > 0 &&
                    (grid[i][j - 1] == 1 || grid[i][j - 1] == 3)) {

                    ways[i][j] =
                        (ways[i][j] + ways[i][j - 1]) % MOD;

                    if (ways[i][j - 1] > 0) {
                        best[i][j] = max(
                            best[i][j],
                            best[i][j - 1] + grid[i][j]
                        );
                    }
                }
            }
        }

        // No valid path
        if (ways[n - 1][n - 1] == 0)
            return {0, 0};

        return {
            (int)ways[n - 1][n - 1],
            best[n - 1][n - 1]
        };
    }
};