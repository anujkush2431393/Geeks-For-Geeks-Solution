class Solution {
  public:
    int countStrings(int n, int k) {
        const int MOD = 1e9 + 7;
        
        // dp[i][j][last] = count of strings of length i,
        // with j adjacent 1-pairs, ending in 'last' (0 or 1)
        // i: 1..n, j: 0..k, last: 0 or 1
        
        vector<vector<array<long long, 2>>> dp(
            n + 1, 
            vector<array<long long, 2>>(k + 1, {0LL, 0LL})
        );
        
        // Base case: length 1, 0 adjacent pairs
        dp[1][0][0] = 1; // string "0"
        dp[1][0][1] = 1; // string "1"
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                // Append '0' — no new pair regardless of last char
                if (dp[i][j][0])
                    dp[i+1][j][0] = (dp[i+1][j][0] + dp[i][j][0]) % MOD;
                if (dp[i][j][1])
                    dp[i+1][j][0] = (dp[i+1][j][0] + dp[i][j][1]) % MOD;
                
                // Append '1' — new pair only if last char was also '1'
                if (dp[i][j][0])
                    dp[i+1][j][1] = (dp[i+1][j][1] + dp[i][j][0]) % MOD;
                
                if (j + 1 <= k && dp[i][j][1])
                    dp[i+1][j+1][1] = (dp[i+1][j+1][1] + dp[i][j][1]) % MOD;
            }
        }
        
        return (dp[n][k][0] + dp[n][k][1]) % MOD;
    }
};