class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> maxEnd(n);
        maxEnd[0] = arr[0];

        // Maximum subarray sum ending at each index
        for (int i = 1; i < n; i++) {
            maxEnd[i] = max(arr[i], maxEnd[i - 1] + arr[i]);
        }

        int sum = 0;
        for (int i = 0; i < k; i++)
            sum += arr[i];

        int ans = sum;

        for (int i = k; i < n; i++) {
            sum += arr[i] - arr[i - k];

            ans = max(ans, sum);
            ans = max(ans, sum + maxEnd[i - k]);
        }

        return ans;
    }
};