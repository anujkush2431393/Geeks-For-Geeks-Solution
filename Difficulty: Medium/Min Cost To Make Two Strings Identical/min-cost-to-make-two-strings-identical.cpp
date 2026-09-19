class Solution {
  public:
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        int n = s1.size();
        int m = s2.size();

        // dp[i][j] = minimum cost to make
        // s1[0..i-1] and s2[0..j-1] identical
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

        // Delete all characters from s1
        for (int i = 1; i <= n; i++)
            dp[i][0] = dp[i - 1][0] + costS1;

        // Delete all characters from s2
        for (int j = 1; j <= m; j++)
            dp[0][j] = dp[0][j - 1] + costS2;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    // Keep this character in both strings
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Delete from s1 OR delete from s2
                    dp[i][j] = min(
                        dp[i - 1][j] + costS1,
                        dp[i][j - 1] + costS2
                    );
                }
            }
        }

        return (int)dp[n][m];
    }
};