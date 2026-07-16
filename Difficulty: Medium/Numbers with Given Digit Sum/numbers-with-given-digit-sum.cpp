class Solution {
  public:
    int countWays(int n, int sum) {
        // If sum is impossible for n digits
        if (sum > 9 * n || sum < 1) return -1;
        
        // DP table: dp[pos][s] = ways to form pos digits with sum s
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        dp[0][0] = 1;  // base case
        
        for (int pos = 1; pos <= n; pos++) {
            for (int s = 0; s <= sum; s++) {
                for (int d = 0; d <= 9; d++) {
                    if (pos == 1 && d == 0) continue; // no leading zero
                    if (s - d >= 0) {
                        dp[pos][s] += dp[pos - 1][s - d];
                    }
                }
            }
        }
        
        return dp[n][sum] == 0 ? -1 : dp[n][sum];
    }
};
