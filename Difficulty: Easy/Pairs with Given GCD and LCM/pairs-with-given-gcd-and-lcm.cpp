class Solution {
  public:
    int pairCount(int x, int y) {
        // LCM must be divisible by GCD
        if (y % x != 0) return 0;

        int n = y / x;
        int count = 0;

        // Find pairs (i, n/i) such that gcd(i, n/i) = 1
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                int j = n / i;

                if (__gcd(i, j) == 1) {
                    if (i == j)
                        count += 1;
                    else
                        count += 2; // (a,b) and (b,a)
                }
            }
        }

        return count;
    }
};