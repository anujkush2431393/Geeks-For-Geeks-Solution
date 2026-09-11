class Solution {
  public:
    int sameMod(vector<int> &arr) {
        int n = arr.size();

        // Find GCD of differences from arr[0]
        int g = 0;

        for (int i = 1; i < n; i++) {
            g = __gcd(g, abs(arr[i] - arr[0]));
        }

        // All elements are equal
        if (g == 0)
            return -1;

        // Count divisors of g
        int count = 0;

        for (int i = 1; i * i <= g; i++) {
            if (g % i == 0) {
                count++;

                if (i != g / i)
                    count++;
            }
        }

        return count;
    }
};