class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();

        // If we can visit all trees
        if (m >= n) {
            int sum = 0;
            for (int x : arr) sum += x;
            return sum;
        }

        // Duplicate array to handle circular subarrays
        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            a[i] = arr[i % n];
        }

        // Sliding window of size m
        long long windowSum = 0;
        for (int i = 0; i < m; i++) {
            windowSum += a[i];
        }

        long long ans = windowSum;

        for (int i = m; i < 2 * n; i++) {
            windowSum += a[i];
            windowSum -= a[i - m];

            // Only consider n different circular windows
            if (i - m + 1 < n) {
                ans = max(ans, windowSum);
            }
        }

        return (int)ans;
    }
};