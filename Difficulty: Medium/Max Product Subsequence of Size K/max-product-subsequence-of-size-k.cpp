class Solution {
  public:
    int maxProduct(vector<int> &arr, int k) {
        // dp[j][0] = maximum product using j elements
        // dp[j][1] = minimum product using j elements
        // Minimum is needed because negative * negative can become maximum.

        const int INF = 1e9;

        vector<long long> mx(k + 1, LLONG_MIN);
        vector<long long> mn(k + 1, LLONG_MAX);

        mx[0] = mn[0] = 1;

        for (int x : arr) {
            // Go backwards so that one element is used only once
            for (int j = k; j >= 1; j--) {
                if (mx[j - 1] == LLONG_MIN)
                    continue;

                long long a = mx[j - 1] * x;
                long long b = mn[j - 1] * x;

                mx[j] = max({mx[j], a, b});
                mn[j] = min({mn[j], a, b});
            }
        }

        return (int)mx[k];
    }
};