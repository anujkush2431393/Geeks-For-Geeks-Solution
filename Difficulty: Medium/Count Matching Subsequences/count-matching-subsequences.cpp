class Solution {
  public:
    int countWays(string &s1, string &s2) {
        const int MOD = 1000000007;

        int n = s1.size();
        int m = s2.size();

        vector<long long> dp(m + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[j + 1] = (dp[j + 1] + dp[j]) % MOD;
                }
            }
        }

        return dp[m];
    }
};