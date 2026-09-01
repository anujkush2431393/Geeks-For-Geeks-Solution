class Solution {
  public:
    int palindromicStrings(int n, int k) {
        const long long MOD = 1000000007;

        long long ans = 0;
        long long perm = 1; // P(k, m)

        for (int m = 0; 2 * m <= n; m++) {

            if (m > 0) {
                perm = (perm * (k - m + 1)) % MOD;
            }

            // Even length = 2*m
            if (m > 0) {
                ans = (ans + perm) % MOD;
            }

            // Odd length = 2*m + 1
            if (2 * m + 1 <= n) {
                long long ways = (perm * (k - m)) % MOD;
                ans = (ans + ways) % MOD;
            }
        }

        return (int)ans;
    }
};